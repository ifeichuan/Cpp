class User():
    def __init__(self, first_name, last_name):
        self.first_name = first_name
        self.last_name = last_name
        self.login_attempts = 0
 
    def increment_login_attempts(self):
        self.login_attempts += 1
 
    def reset_login_attempts(self):
        self.login_attempts = 0
     
user_1 = User("John","Smith")
user_1.increment_login_attempts()
user_1.increment_login_attempts()
user_1.increment_login_attempts()
print(user_1.login_attempts)

user_1.reset_login_attempts()
print(user_1.login_attempts)
 
class Admin(User):
    def __init__(self, first_name, last_name,privileges):
        super().__init__(first_name, last_name)
        self.privileges = Privileges(privileges)
       
    
class Privileges:
    def __init__(self,privileges):
        self.pravileges = privileges
    def show_privileges(self):
         for i in self.pravileges:
            print(f"{i}")

privileges = ['can add post','can delete post','can ban user']

admin = Admin('Fei','Chuan',privileges)
admin.privileges.show_privileges()