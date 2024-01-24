import sys
import pygame
from settings import Settings
from ship import Ship
from bullet import Bullet
from alien import Alien
import random

class AlienInvasion:
    # 管理游戏资源和行为类
    def __init__(self) -> None:
        # 初始化游戏并创建游戏资源
        pygame.init()

        self.settings = Settings()#设置窗口尺寸
        self.screen = pygame.display.set_mode((self.settings.screen_width,self.settings.screen_height))
        self.settings.screen_height = self.screen.get_rect().height
        self.settings.screen_width = self.screen.get_rect().width
        pygame.display.set_caption("Alien Invasion")
        self.ship = Ship(self)
        self.bullets = pygame.sprite.Group()
        self.aliens = pygame.sprite.Group()
        self._create_fleet()
        # 设置背景色
    def run_game(self):
        # 开始游戏主循环
        while True:
            self._check_events()
            self.ship.update()
            self.bullets.update()
            self._update_bullets()
            self._update_aliens()
            self._update_screen()
            

            

    def _check_events(self):
            # 监听鼠标和键盘事件
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
              sys.exit()
            elif event.type == pygame.KEYDOWN:
                self._check_keydown_events(event)
                if event.key == pygame.K_F1:
                    self.settings.ship_speed +=0.2
                if event.key == pygame.K_F2:
                    self.settings.ship_speed -=0.2
                if event.key == pygame.K_q:
                    sys.exit()
                if event.key == pygame.K_SPACE:
                    self._fire_bullet()
            elif event.type == pygame.KEYUP:
                self._check_keyup_events(event)
            

    def _check_keydown_events(self,event):
        # 处理按下事件
        if event.key == pygame.K_RIGHT:
            self.ship.moving_right = True
        if event.key == pygame.K_LEFT:
            self.ship.moving_left = True
        if event.key == pygame.K_UP:
            self.ship.moving_up = True
        if event.key == pygame.K_DOWN:
            self.ship.moving_down = True

    def _check_keyup_events(self,event):
        # 处理松开事件
        if event.key == pygame.K_RIGHT:
           self.ship.moving_right = False
        if event.key == pygame.K_LEFT:
            self.ship.moving_left = False
        if event.key == pygame.K_UP:
            self.ship.moving_up = False
        if event.key == pygame.K_DOWN:
            self.ship.moving_down = False

    def _fire_bullet(self):
        if len(self.bullets) < self.settings.bullet_allowed:
            new_bullet = Bullet(self)
            self.bullets.add(new_bullet)
    
    def _update_bullets(self):
        for bullet in self.bullets.copy():
             if bullet.rect.bottom <=0:
                self.bullets.remove(bullet)
        print(len(self.bullets))

    def _create_fleet(self):
        alien = Alien(self)
        alien_width,alien_height =  alien.rect.size
        available_space_x = self.settings.screen_width - (2*alien_width)
        number_aliens_x = available_space_x // (2*alien_width) # 每行可用位置
        # 计算屏幕可容纳多少行外星人
        ship_height = self.ship.rect.height
        available_space_y = (self.settings.screen_height
                             ) - (3*alien_height) - ship_height
        number_rows = available_space_y // (2*alien_height)
        for row_number in range(number_rows):
            for alien_number in range(number_aliens_x):
                self._create_alien(alien_number,row_number)

    def _create_alien(self,alien_number,row_number):
        alien = Alien(self)
        alien_width , alien_height = alien.rect.size
        alien.x = alien_width + 2*alien_width * alien_number
        alien.rect.x = alien.x + random.randint(-50,50) -  10*alien_number
        alien.rect.y = alien.rect.height + 2*alien.rect.height * row_number  + random.randint(-50,50) - 10*row_number
        for alien_compare in self.aliens.sprites():
                if pygame.sprite.collide_rect(alien_compare,alien):
                    alien.rect.x += alien_compare.rect.x - alien.rect.x 
                    alien.rect.y += alien_compare.rect.y - alien.rect.y 
        self.aliens.add(alien)
    
    def _update_aliens(self):
        self._check_fleet_edges()
        self.aliens.update()
    
    def _check_fleet_edges(self):
        """有外星人到达边缘时采取相应的措施。"""
        for alien in self.aliens.sprites():
            if alien.check_edges():
                self._change_fleet_direction()
                break
    def _change_fleet_direction(self):
        """将外星人下移"""
        for alien in self.aliens.sprites():
            alien.rect.y += self.settings.fleet_drop_speed
            self.settings.fleet_direction *= -1
    def _update_screen(self):
        # 让最近绘制的屏幕可见
        self.screen.fill(self.settings.bg_color)
        self.ship.blitme()
        for bullet in self.bullets.sprites():
            bullet.draw_bullet()
            for alien in self.aliens.sprites():
                if pygame.sprite.collide_rect(alien,bullet):
                    self.aliens.remove(alien)
                    self.bullets.remove(bullet)
                    print("清除")
        self.aliens.draw(self.screen)
        pygame.display.flip()

if __name__ == "__main__":
    # 创建实例并运行游戏
    ai = AlienInvasion()
    ai.run_game()
