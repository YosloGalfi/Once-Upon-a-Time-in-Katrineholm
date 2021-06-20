# Once-Upon-a-Time-in-Katrineholm
Large game project with friends and other students

Created using our own game engine, with DirectX 11. 
Every collaborator has provided either rendering and graphics techniques or gameplay elements. 
The game takes place in a forest where the player must follow the road in order to get to the end. 
The environment around the player is toxic, and the player must keep close to the house in order to survive. 
The house will follow the road as long as the player is in radius, otherwise the house will stand still. 
The house also needs fuel, which the player can find in the environment and then give to the house. 
But there are other dangers than the fog in the forest. 

My contributions to this project was mainly an asset manager, FXAA, gameplay logic regarding the interactions between the house and the player and memory leaks. 

The asset manager loads 1 version of every model, texture, shader and so on, in order to keep the VRAM and RAM usage to a minimum requirement. Every copy of each model then points to the same vertex and index buffers, textures e.t.c.. 

The FXAA implementation is based on the example found on Nvidias homepage. No other anti-aliasing technique is present in the game. 
