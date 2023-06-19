# nat 
enable http service on server
and give the ip address to the all the components 
and routing must be set 
enable
config
ip nat inside source static 10.0.0.254 200.something ip
int s2/0 
ip nat outside
exit

int fa0/0 
ip nat inside
exit

show run 



