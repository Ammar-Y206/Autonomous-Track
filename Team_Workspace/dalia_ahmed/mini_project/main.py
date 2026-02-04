from robots import robot,rover,drone
d1=drone("drone1","s123")
r1=rover("rover1","s122")
d2=drone("drone2","s121")
fleet=[
    d1,
    r1,
    d2
]
for robot in fleet:
    if robot.battery<=20:
        print("LOW BATTERY")
        robot.stop()
        robot.recharge()
    else:
        robot.move()

    