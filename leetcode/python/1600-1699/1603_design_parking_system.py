from typing import List
from functools import reduce


class ParkingSystem:
    hashmap = {3: 'small', 2: 'medium', 1: 'big'}

    def __init__(self, big: int, medium: int, small: int):
        self.values = {'small': small, 'medium': medium, 'big': big}

    def addCar(self, carType: int) -> bool:
        for k, v in self.hashmap.items():
            if k == carType:
                if self.values[v]:
                    self.values[v] = self.values[v] - 1
                    return True
                else:
                    return False


obj = ParkingSystem(1, 2, 3)
param_1 = obj.addCar(2)
# print(solution.maximumWealth(accounts = [[1,2,3],[3,2,1]]))