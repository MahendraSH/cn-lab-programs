# configure a cisco router as a DHCP server
enable 
config
int fa0/0
ip address 192.12.12.1 255.255.255.0
no shut
exit

dhcp pool pool1
network 192.12.12.0 255.255.255.0
default-router 192.12.12.1
dns-server 192.12.12.1
exit

dhcp excluded-address 192.12.12.1 192.12.12.100

