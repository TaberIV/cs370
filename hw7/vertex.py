import math

class vertex:
  def __init__(self, x, y, value):
    self.x = x
    self.y = y
    self.value = value
    self.minSum = math.inf
    self.parent = None
    self.dequeued = False

  def __lt__(self, value):
    return self.minSum < value.minSum