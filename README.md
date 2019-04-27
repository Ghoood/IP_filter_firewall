# IP_filter_firewall

__To generate *.ko file for install__

  write a Makefile and then follow the following
  Before use, should edit the IP adddress to target server address in the similar format as "\x67\xEB\x2E\x27"

**To install the module, type**

`sudo insmod firewall_ip.ko`


**To remove the module, type:**

`sudo rmmod firewall_ip`


**To verify the module is actually loaded or unloaded, type:**

`dmesg | tail 
or
dmesg`
