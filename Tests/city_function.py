import unittest

def city_country(city,country,population=''):
    """城市名 and 国家名 *人口"""
    if population:
        full_city_country = f"{city} {country} {population}"
    else: 
        full_city_country = f"{city} {country}"
    
    return full_city_country.title()

