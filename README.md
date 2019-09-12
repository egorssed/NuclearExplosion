# NuclearExplosion
Симмуляция ядерного взрыва
Изначально имеется сфера , в которой могут происходить спонтанные ядерные распады , продуктами которых являются интересующие нас нейтроны
Нейтроны при рождении получают произвольные направления и скорости , двигаются на масштабах длины свободного пробега до столкновения с ядром , либо ухода из зоны взрыва. Расчет видется дискретно , каждая итерация - новое поколение нейтронов.
Так как при столкновении с ядром есть вероятность рождения от 0 до 4 нейтронов , некоторые ядерные реакции могут обрываться так как все нейтроны поглотились ядрами.
В выводимых данных:
generation - текущее поколение нейтронов ( количество столкновения)
Number of neutrons - текущее количество нейтронов в активной зоне
amount of finite processes - количество ядреных реакций закончившихся поглощением всех нейтронов (ядерный взрыв не произошел)
amount of infinite processes - количество ядреных реакций , в которых количество нейтронов растет до бесконечности (ядерный взрыв)
