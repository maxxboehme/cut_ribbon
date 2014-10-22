#!/usr/bin/env python
from __future__ import print_function
import sys
import random
import time

BARS = 50
MAX = 3000

def _print_loading_bar(x, newline, maxLimit, numberBars):
   percentag = (x*100) / maxLimit
   #print "percentage: " + str(percentag)
   colums = 100.0 / numberBars
   #print "colums: " + str(colums)
   bars = int(percentag / colums)
   #print "bars: " + str(bars)
   arrow = ">" if (bars != numberBars) else ""
   print("[" + ("=" * bars) + arrow + (" " * (numberBars - bars - 1))+"]")
   if not newline:
      sys.stdout.write("\033[F") # Cursor up one line

def _print_loading_bar2(x, newline, maxLimit, numberBars):
   percentag = (x*100) / maxLimit
   #print "percentage: " + str(percentag)
   colums = 100.0 / numberBars
   #print "colums: " + str(colums)
   bars = int(percentag / colums)
   #print "bars: " + str(bars)
   arrow = ">" if (bars != numberBars) else ""
   end = '\n' if newline else '\r'
   print("[" + ("=" * bars) + arrow + (" " * (numberBars - bars - 1))+"]", end=end)
   sys.stdout.flush()

def _main(args):
   for i in xrange(0, MAX+1):
      newline = True if i == MAX else False
      _print_loading_bar(i, newline, MAX, BARS)
      time.sleep(10/MAX)

if __name__ == "__main__":
   retCode = _main(sys.argv[1:])
   sys.exit(retCode)
