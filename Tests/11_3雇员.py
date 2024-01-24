import unittest
class Employee:
    # 员工年薪
    def __init__(self,first,last,salary) -> None:
        # 初始化
        self.first = first
        self.last = last
        self.salary = salary
    def give_raise(self,salary=5000):
        # 默认增加5k年薪,指定
        self.salary += salary
    

class EmployeeTestcase(unittest.TestCase):

    def setUp(self) -> None:
        self.Emplpyee = Employee("Fei","Chuan",200000)

    
    def test_give_default_raise(self):
        self.Emplpyee.give_raise()
        self.assertEqual(self.Emplpyee.salary,205000)
    def test_give_custom_raise(self):
        self.Emplpyee.give_raise(99999)
        self.assertEqual(self.Emplpyee.salary,299999)

        
if __name__ == "__main__":
    unittest.main()