# VulnAddUserScript
Vulnerable "innocent looking" script with the intention of being a SUID executable to perform a local linux privilege escalation via manipulation of PATH variable 
- The vulnerable command is "mkdir" because the full path is not specified. This is generally bad practice, especially in SUID files with root as the owner

two ways this script can be used to spawn a root shell:
1. ./VulnAddUserScript ';/bin/bash;' <somepassword>
  this method interupts the priviledged command "useradd" and terminates it to spawn a root shell via "/bin/bash"
  
2. Intercept current user PATH variable
  the user running the script can append a directory to the begginging of their own PATH variable (such as a world readable     directory like /tmp) and create a file titled "mkdir" that contains "/bin/sh" as its only content. This will use the           effective user ID (0) to spawn a root shell
   
