class Settings:
    # 存储游戏Alieninvasion中所有设置类
    def __init__(self) -> None:
        self.screen_width = 1200
        self.screen_height = 800
        self.bg_color = [230,230,230]
        self.ship_speed = 0.5
        self.bullet_speed = 0.5   
        self.bullet_width = 3
        self.bullet_height = 15
        self.bullet_color = (60,60,60)
        self.bullet_allowed = 8 # 最大子弹数量
        self.ailen_speed = 0.2
        self.fleet_drop_speed = 12
        self.fleet_direction = 1
        #fleet_direction =1 right moving -1 left moving
        
        