class Restaurant():
 
     def __init__(self,restaurant_name, cuisine_type):
         self.restaurant_name = restaurant_name
         self.cuisine_type = cuisine_type
         self.number_served = 0
 
     def describe_restaurant(self):
         print(f"restaurant name is {self.restaurant_name}")
         print(f"cuisine type is {self.cuisine_type}")
 
     def open_restaurant(self):
         print("Open")
 
     def set_number_served(self, number):
         self.number_served = number
         print(f"{self.number_served} person has served!")
 
     def increment_number_served(self, numbers):
         self.number_served += numbers
         print(f"{self.number_served} person has served!")
 
restaurant = Restaurant("chuancai", "hot pot")
restaurant.set_number_served(10)
restaurant.increment_number_served(20)
restaurant.increment_number_served(30)

class IceCreamStand(Restaurant):
    def __init__(self, restaurant_name, cuisine_type,flavors):
        super().__init__(restaurant_name, cuisine_type)
        self.flavors = flavors
    def get_flavors(self):
        for i in self.flavors:
            print(f"This is {i.title()}")

icecream = IceCreamStand('Ruby','Flavors',['Ice','Hot','Cx','xun'])
icecream.get_flavors()