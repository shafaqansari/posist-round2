# posist-round2

Program is divided into various modules
- User Login/Registeration(for new users)
- Validation
- Encryption
- New Data Entry
- Editing of previous data
- Saving Newly Created/Modified data
user login
The program consist of two options
login for users already present in database and registeration for new members;
for this, program takes user details as input eg user id,password etc
everything is menu driven hence user will find it interactive and easier to surf the prog.
For encrytion Caesar Cypher has been used(for simplicity).
for storing records- hashmap has been used which stores uder id,password and genesis node created by particular owner.
Here for simplicity assumption is made that single user has created single genesis node and can perform editing on that node(root) only. For user creating multiple genesis vector of nodes has to be incorporated.
Libraries required-
#include<unordered_map>
#include<cstring>
#include<vector>
#include<cmath>
  
all that is done using parent library #include<bits/stdc++.h>
Assumption- for simplicity binary tree has been considered
functions made:
Creation- For new genesis node creating
NewNode- For adding new node to existing tree
Encrypt- For encrypting user password using caesar cypher
Decrypt- For decrypting user password
EditSubtree- for editing subtree root
EditLeaf- for editing leaf value
TransferOwnership- for transfering the ownership from old to new owner.
LongestChain- which prints longest chain of genesis node.
merge- for merging data of two nodes

GOTO Labels are used for transfering controls.
