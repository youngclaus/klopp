import piszczek.List as List, random
pinv = [0]

def say(p):
  print(p.name + " #" + p.no + ", " + p.typ + ", Lvl " + p.lvl + ", HP: " + str(p.hpm) + ", Atk1: " + p.atk1.name + ", Atk2: " + p.atk2.name)

def checkp():
  y = 0
  say(pinv[y])
      
def heal():
  if (pinv[0] != 0):
    pinv[0].hp = pinv[0].hpm
    print(pinv[0].name + "'s hp has been restored.")
  else:
    print("Empty")
      
def catch(p):
  x = random.randint(1,(int(p.hp)))
  if (int(x)>=int(p.hp)):
    print("You caught " + p.name)
    pinv[0] = p
    return True
  else:
    print("You failed to catch " + p.name + "\n")
    return False
    
def counter(pa, pd):
  x = random.randint(1,2)
  if (x == 1):
    print(pd.name + " used " + pd.atk1.name + " on " + pa.name + ".")
    pa.hp -= pd.atk1.dmg
    if (pa.hp <= 0):
      print(pa.name + ": 0" + "/" + str(pa.hpm) + " HP.\n")
    else:
      print(pa.name + ": " + str(pa.hp)  + "/" + str(pa.hpm) + " HP.")
  else:
    print(pd.name + " used " + pd.atk2.name + " on " + pa.name + ".")
    pa.hp -= pd.atk2.dmg
    if (pa.hp <= 0):
      print(pa.name + ": 0" + "/" + str(pa.hpm) + " HP.\n")
    else:
      print(pa.name + ": " + str(pa.hp)  + "/" + str(pa.hpm) + " HP.")
  
def battle(pa, pd):
  print("\nYou have entered battle with a " + pd.name + ".")
  print("What would you like to do?")
  tf = True
  while (tf == True):
    if (pd.hp > 0 and pa.hp>0):
      pick = input("(1)" + pa.atk1.name + ", (2)" + pa.atk2.name + ", (3)Catch")
      if (pick == '1'):
        attack1(pa, pd)
      elif (pick == '2'):
        attack2(pa, pd)
      elif (pick == '3'):
        x = catch(pd)
        if (x == True):
          tf = False
    elif (pd.hp <= 0):
      print("You won the battle!")
      tf = False
    else:
      print("You lost the battle! Start over!")
      tf = False
      exit()
    if (pd.hp > 0):
      counter(pa, pd)
      
def attack1(pa, pd):
  print(pa.name + " used " + pa.atk1.name + " on " + pd.name + ".")
  pd.hp -= pa.atk1.dmg
  if (pd.hp <= 0):
    print(pd.name + ": 0" + "/" + str(pd.hpm) + " HP.")
  else:
    print(pd.name + ": " + str(pd.hp)  + "/" + str(pd.hpm) + " HP.\n")
  
def attack2(pa, pd):
  print(pa.name + " used " + pa.atk2.name + " on " + pd.name + ".")
  pd.hp -= pa.atk2.dmg
  if (pd.hp <= 0):
    print(pd.name + ": 0" + "/" + str(pd.hpm) + " HP.")
  else:
    print(pd.name + ": " + str(pd.hp)  + "/" + str(pd.hpm) + " HP.\n")
  
def trade():
  tf = True
  print("\n")
  for x in range(0,3):
    print(List.p[x].name)
  newp = input("What Pokemon would you like to switch with " + pinv[0].name + "?\n")
  while (tf == True):
    for x in range(0,3):
      if (newp == List.p[x].name):
        pinv[0] = List.p[x]
        say(pinv[0])
        tf = False
        break
      else:
        newp = input("Please pick a valid Pokemon.")
        
def battlerand(pa):
  x = random.randint(0,4)
  pd = List.p[x]
  print("You have entered battle with a " + pd.name + ".")
  print("What would you like to do?")
  tf = True
  while tf:
    if (pd.hp > 0 and pa.hp>0):
      pick = input("(1)" + pa.atk1.name + ", (2)" + pa.atk2.name + ", (3)Catch")
      if (pick == '1'):
        attack1(pa, pd)
      elif (pick == '2'):
        attack2(pa, pd)
      elif (pick == '3'):
        x = catch(pd)
        if (x == True):
          tf = False
    elif (pd.hp <= 0):
      print("You won the battle!")
      tf = False
    else:
      print("You lost the battle! Start over!")
      tf = False
      exit()
    if (pd.hp > 0):
      counter(pa, pd)
  
def prompt(atHome):
  while True:
    y = "\nChoose an option:\n(1)Continue Adventure\n(2)Battle Wild Pokemon\n(3)Check Pokemon\n(4)Heal Pokemon"
    if atHome == True:
      y += "\n(5)Trade Pokemon\n(6)Close Game"
      x = input(y)
      if (x == ('1' or '2' or '3' or '4' or '5')):
        if (x == '1'):
          battlerand(pinv[0])
        elif (x == '2'):
          trade()
        elif (x == '3'):
          checkp()
        elif (x == '4'):
          heal()
        elif (x == '5'):
          trade()
      elif (x == '6'):
        break
    else:
      y += "(5)Close Game"
      x = input(y)
      if (x == ('1' or '2' or '3' or '4' or '5')):
        if (x == '1'):
          battlerand(pinv[0])
        elif (x == '2'):
          trade()
        elif (x == '3'):
          checkp()
        elif (x == '4'):
          heal()
        elif (x == '5'):
          break
  

      
