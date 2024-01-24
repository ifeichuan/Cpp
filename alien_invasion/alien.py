import pygame
import sys
from pygame.sprite import Sprite
class Alien(Sprite):
    def __init__(self,ai_game):
        super().__init__()
        self.screen = ai_game.screen
        self.settings = ai_game.settings
        # 加载外星人图像
        self.image = pygame.image.load(r"C:\Users\Feich\OneDrive\Documents\项目\Python\alien_invasion\images\alien.png")
        self.rect = self.image.get_rect()
        self.rect.x = self.rect.width
        self.rect.y = self.rect.height
        self.x = float(self.rect.x)
    def update(self):
        self.x += self.settings.ailen_speed * self.settings.fleet_direction
        self.rect.x = self.x
    def check_edges(self):
        """如果外星人位于屏幕边缘，就返回True"""
        screen_rect = self.screen.get_rect()
        if self.rect.right >= screen_rect.right or self.rect.left<screen_rect.left :
            return True
    def check_bottom(self):
        """如果触底，则"""
        screen_rect = self.screen.get_rect()
        if self.rect.bottom > screen_rect.bottom:
            return True
    