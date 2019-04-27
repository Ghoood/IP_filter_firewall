#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/ip.h>
#include <linux/skbuff.h>
#include <linux/tcp.h>
#include <linux/inet.h>


static struct nf_hook_ops nfho; 
static unsigned char* ip = "\x67\xEB\x2E\x27";

unsigned int hook_func_incoming(void *priv, 
                                struct sk_buff *skb,
                                const struct nf_hook_state *state) 
{

  if (!skb || !ip_hdr(skb))
    return NF_ACCEPT;

  if (ip_hdr(skb)-> daddr == *(unsigned int*)ip)
    return NF_DROP;
  
  
  return NF_ACCEPT;
}


int init_module()
{

  nfho.hook = hook_func_incoming; 

  nfho.hooknum = NF_INET_LOCAL_OUT; 

  nfho.pf = PF_INET;                          
 
  nfho.priority = NF_IP_PRI_FIRST;  

  nf_register_net_hook(&init_net, &nfho);                    
  
  printk(KERN_INFO "ip filter firewall loaded\n");
  return 0;
}

void cleanup_module()
{ 
  printk("ip filter firewall unloaded\n");
  nf_unregister_net_hook(&init_net, &nfho);   
}
