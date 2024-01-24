import unittest
from city_function import  city_country

class CitysTestCase(unittest.TestCase):

    def test_city_country(self):
        full_city_country = city_country("yangxin","china")
        self.assertEqual(full_city_country,"Yangxin China")
    def test_city_country_population(self):
        full_city_courty_population = city_country("wuhan","china","1100w")
        self.assertEqual(full_city_courty_population,"Wuhan China 1100W")
if __name__ == "__main__":
    unittest.main()

