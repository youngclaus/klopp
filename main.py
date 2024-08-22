import List, Constructors

name = input("What is your name?")
rival = input("Who is your rival?")
print("Welcome to the world of Pokemon, " + name + ". You will explore new lands, meet new people, and conquer new adventures on your journey through CYLandia.")
tf = True
while (tf == True):
  picknum = int(input(name + ", select your first Pokemon: \n(1)Bulbasaur, \n(2)Charmander, \n(3)Squirtle."))
  if (picknum == 1):
    print("\nYou picked Bulbasaur!")
    Constructors.pinv[0] = List.p[0]
    Constructors.say(Constructors.pinv[0])
    tf1 = False
    break
  elif (picknum == 2):
    print("\nYou picked Charmander!")
    Constructors.pinv[0] = List.p[1]
    Constructors.say(Constructors.pinv[0])
    tf1 = False
    break
  elif (picknum == 3):
    print("You picked Squirtle!")
    Constructors.pinv[0] = List.p[2]
    Constructors.say(Constructors.pinv[0])
    tf1 = False
    break
print("\nYour journey awaits.\n")

#-----------------------------------------------------------
#-----------------------------------------------------------

print("Mom: " + name + ". Professor Puglise is here to see you!");
tf = True
while(tf == True):
  prompt = int(input("You go downstairs to meet Puglise. \n(1)Say hi. \n(2)What do you want?"))
  if (prompt == 1):
    print("\nPuglise: Hello " + name + ", I see you have a Pokemon there... I need you to do something for me. Are you up to the task?")
    tf = False
    break
  elif (prompt == 2):
    print("\nPuglise: I need a favor, and this is not something in your control. Are you up for it?\n")
    tf = False
    break
tf = True
while (tf == True):
  prompt = input("(1)Yes or (2)no?")
  if (int(prompt) == 1):
    print("\nPuglise: Then let us begin.")
    tf = False
    break
  elif (int(prompt) == 2):
    print("\nPuglise: Why, of course you are!")
    tf = False
    break
  else:
    prompt = input("Yes or no?")
print("Puglise: Your job is to travel up the road to Route 1 and take out the Jigglypuffs that attacked your friend, " + rival + ". Good Luck.\n")  

#-----------------------------------------------------------
#-----------------------------------------------------------
  
prompt = int(input("(1)Travel up the road, \n(2)Check Pokemon, \n(3)Heal Pokemon"))
tf = True
while (tf == True):
  if (prompt != 1 and prompt != 2 and prompt != 3):
    prompt = int(input("\n(1)Travel up the road, \n(2)Check Pokemon, \n(3)Heal Pokemon"))
  elif (prompt == 2):
    print(Constructors.checkp())
    prompt = int(input("\n(1)Travel up the road, \n(2)Check Pokemon, \n(3)Heal Pokemon"))
  elif (prompt == 3):
    Constructors.heal()
    prompt = int(input("\n(1)Travel up the road, \n(2)Check Pokemon, \n(3)Heal Pokemon"))
  else:
    tf = False
    break
print("\nYou reach the Jigglypuffs and one attacks you.")
Constructors.battle(Constructors.pinv[0], List.p[3])
  
#-----------------------------------------------------------
#-----------------------------------------------------------
  
print("\n" + rival + ": Thanks, " + name + ". You saved my life, those Jigglypuffs almost killed me. Now I can battle you!")
tf = True
prompt = int(input("\n(1)Battle, \n(2)Check Pokemon, \n(3)Heal Pokemon"))
while (tf == True):
  if (prompt != 1 and prompt != 2 and prompt != 3):
    prompt = int(input("\n(1)Battle, \n(2)Check Pokemon, \n(3)Heal Pokemon"))
  elif (prompt == 2):
    print(Constructors.checkp())
    prompt = int(input("\n(1)Battle, \n(2)Check Pokemon, \n(3)Heal Pokemon"))
  elif (prompt == 3):
    Constructors.heal()
    prompt = int(input("\n(1)Battle, \n(2)Check Pokemon, \n(3)Heal Pokemon"))
  else:
    tf = False
    break
Constructors.battle(Constructors.pinv[0], List.p[2])

print("Wow, your good! Let's head back to the professor.")
tf2 = True
while (tf2 == True):
  prompt = input("\n(1)Go to professor\n(2)Check Pokemon\n(3)Heal Pokemon")
  if (prompt == '1'):
    tf2 = False
    break
  elif (prompt == '2'):
    print(Constructors.checkp())
  elif (prompt == '3'):
    Constructors.heal()

#-----------------------------------------------------------
#-----------------------------------------------------------

print("\nProf. Puglise: Welcome, I see you saved your friend. There are great things in your future, " + name + ". Please, allow me to show you the trade-in machine. This machine allows you to swap your Pokemon for a new one- any one you want. Just know that you can only hold one at a time. If you ever want to use it, come to my lab. Farewell, " + name + " and " + rival + ".")

Constructors.prompt(True)