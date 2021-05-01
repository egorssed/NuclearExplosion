# NuclearExplosion

En

Simulation of a nuclear explosion.

Initially, there is a sphere in which spontaneous nuclear decays can occur, the products of which are the neutrons we are interested in. Neutrons at birth receive arbitrary directions and velocities, move on the scale of the free path length before colliding with a nucleus or leaving the explosion zone. The calculation is carried out discretely, each iteration is a new generation of neutrons.
Since in the collision of the nucleus there is a probability of birth of 0 to 4 neutrons, some nuclear reactions may be terminated since all neutrons are absorbed by the nuclei.

Depending on the initial number of neutrons and radius of the sphere, initial neutrons can start exponential growth of neutron number, hence explosion, or otherwise leave the sphere or be absorbed by nuclei.

Given the initial number of neutrons and radius of the sphere, the program carries out several tests and returns statistics of explosion probability by calculating the number of events that ended up with an explosion and the number of events that ended up with an absence of free neutrons. 

In the output data:

generation - the current generation of neutrons ( number of collisions)
Number of neutrons - current number of neutrons in the core
amount of finite processes - number of nuclei reactions which have terminated by absorption of all neutrons (nuclear explosion has not happened)
amount of infinite processes - number of nuclear reactions in which the number of neutrons increases to infinity (nuclear explosion)



Ru


Симмуляция ядерного взрыва.  
Изначально имеется сфера , в которой могут происходить спонтанные ядерные распады , продуктами которых являются интересующие нас нейтроны. 
Нейтроны при рождении получают произвольные направления и скорости , двигаются на масштабах длины свободного пробега до столкновения с ядром , либо ухода из зоны взрыва. Расчет видется дискретно , каждая итерация - новое поколение нейтронов.  
Так как при столкновении с ядром есть вероятность рождения от 0 до 4 нейтронов , некоторые ядерные реакции могут обрываться так как все нейтроны поглотились ядрами.  

В выводимых данных:  
 - generation - текущее поколение нейтронов ( количество столкновения)  
 - Number of neutrons - текущее количество нейтронов в активной зоне  
 - amount of finite processes - количество ядреных реакций закончившихся поглощением всех нейтронов (ядерный взрыв не произошел)  
 - amount of infinite processes - количество ядреных реакций , в которых количество нейтронов растет до бесконечности (ядерный взрыв)  
