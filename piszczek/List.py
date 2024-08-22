import Constructors
p = [None]*400
pm = [None]*400

class pokemon:
  def __init__(self, name, no, typ, lvl, hp, hpm, atk1, atk2):
    self.name = name
    self.no = no
    self.typ = typ
    self.lvl = lvl
    self.hp = hp
    self.hpm = hpm
    self.atk1 = atk1
    self.atk2 = atk2
    
class move:
  def __init__(self, name, no, dmg):
    self.name = name
    self.no = no
    self.dmg = dmg
    
pm[1] = move("Tackle", '1', 5)
pm[2] = move("Growl", '2', 0)
pm[3] = move("Sing", '3', 0)
pm[4] = move("Pound", '4', 3)
pm[5] = move("Tail Whip", '5', 0)

p[0] = pokemon('Bulbasaur', '1', 'Grass', '5', 20, 20, pm[4], pm[2])
p[1] = pokemon('Charmander', '4', 'Fire', '5', 16, 16, pm[1], pm[2])
p[2] = pokemon('Squirtle', '7', 'Water', '5', 18, 18, pm[1], pm[5])
p[3] = pokemon('Jigglypuff', '39', 'Common', '4', 24, 24, pm[4], pm[3])
p[4] = pokemon('Farfetch\'d', '90', 'Common', 
'4', 21, 21, pm[4], pm[5])

  


  
  



