from pynput import keyboard 

up = 0
down = 0
left = 0
right = 0
jump = 0
dash = 0
climb = 0 #fuck you
demo = 0
reset = 0
def update():
	file = open("tmp","w")
	file.write(f"{up}{down}{left}{right}{jump}{dash}{climb}{demo}{reset}")
def on_press(key):
	Key=keyboard.Key
	if key == Key.up:
		global up 
		up = 1
	if key == Key.down:
		global down
		down = 1
	if key == Key.left:
		global left
		left = 1
	if key == Key.right:
		global right
		right = 1
	if key == Key.shift:
		global climb
		climb = 1
	if str(key) == "\'c\'":
		global demo
		demo = 1
	if str(key) == "\'r\'":
		global reset
		reset = 1
	if str(key) == "\'z\'":
		global jump
		jump = 1
	if str(key) == "\'x\'":
		global dash
		dash = 1
	update()
def on_release(key):
	Key=keyboard.Key
	if key == Key.up:
		global up 
		up = 0
	if key == Key.down:
		global down
		down = 0
	if key == Key.left:
		global left
		left = 0
	if key == Key.right:
		global right
		right = 0
	if key == Key.shift:
		global climb
		climb = 0
	if str(key) == "\'c\'":
		global demo
		demo = 0
	if str(key) == "\'r\'":
		global reset
		reset = 0
	if str(key) == "\'z\'":
		global jump
		jump = 0
	if str(key) == "\'x\'":
		global dash
		dash = 0
	update()
with keyboard.Listener(
        on_press=on_press,
        on_release=on_release) as listener:
    listener.join()
