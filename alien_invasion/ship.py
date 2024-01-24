import pygame

class Ship:
    # 管理飞船的类
    def __init__(self,ai_game) -> None:
        self.screen = ai_game.screen
        self.screen_rect = ai_game.screen.get_rect()
        self.settings = ai_game.settings
        # 加载飞船图形并获取其外接矩形
        self.image = pygame.image.load(r"C:\Users\Feich\OneDrive\Documents\项目\Python\alien_invasion\images\ship.bmp")
        self.rect = self.image.get_rect()

        # 对于每艘新飞船，都将其放在屏幕底部的中央
        self.rect.midbottom = self.screen_rect.midbottom
        # 移动标志
        self.moving_right = False
        self.moving_left = False
        self.moving_down = False
        self.moving_up = False
        # 存储小数值
        self.x = float(self.rect.x)
        self.y = float(self.rect.y)
        
    def update(self):
        if self.moving_right and self.rect.right <self.screen_rect.right:
                self.x+=self.settings.ship_speed
        if self.moving_left and self.rect.left >0:
                self.x-=self.settings.ship_speed
        if self.moving_down and self.rect.bottom < self.screen_rect.bottom:
                self.y+=self.settings.ship_speed
        if self.moving_up and self.rect.top >0:
                self.y-=self.settings.ship_speed
        self.rect.x = self.x
        self.rect.y = self.y

    def blitme(self):
        #于指定位置绘制飞船
        self.screen.blit(self.image,self.rect)

