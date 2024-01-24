import unittest
from city_function import  city_country

class CitysTestCase(unittest.TestCase):

    def test_city_country(self):
        full_city_country = city_country("yangxin","china")
        self.assertEqual(full_city_country,"Yangxin China")


if __name__ == "__main__":
    unittest.main()

