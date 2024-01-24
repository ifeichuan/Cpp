class Car:
    def __init__(self,make,model,year):
        self.make = make
        self.model = model
        self.year = year
        self.odometer_reading = 0

    def get_descriptive_name(self):
        """返回基本信息"""
        long_name = f"{self.model} {self.make} {self.year}"
        return long_name.title()
    def read_odometer(self):
        print(f"This car has {self.odometer_reading} miles on it")
    def update_odometer(self,mileage):
        """禁止翻新车！"""
        if(mileage >= self.odometer_reading): self.odometer_reading = mileage
        else: print("You can't roback an odometer!")
    def increment_odometer(self,increment):
        self.odometer_reading += increment

my_used_car = Car('subaru','outback',2015)
print(my_used_car.get_descriptive_name())
my_used_car.update_odometer(23_500)
my_used_car.read_odometer()
my_used_car.increment_odometer(1_200)
my_used_car.read_odometer()

class Battery:
    """电池容量"""
    def __init__(self,battery_size=75):
        self.battery_size = battery_size
    def describe_battery(self):
        print(f"This car has a {self.battery_size} -kWh battery")
    def upgrade_battery(self):
        if self.battery_size != 100:
            self.battery_size = 100
    

class ElectricCar(Car):
    """电动车"""
    def __init__(self, make, model, year,*battery):
        super().__init__(make, model, year)
        self.battery = Battery(*battery)

my_tesla = ElectricCar('tesla','model s',2019,42)
print(my_tesla.get_descriptive_name())
my_tesla.battery.describe_battery()
