# VulnAddUserScript
Vulnerable script with the intention of being a SUID executable to perform a local linux privilege escalation via manipulation of PATH variable 
The vulnerable command is "mkdir" because the full path is not specified. This is generally bad practice, especially in SUID files with root as the owner
