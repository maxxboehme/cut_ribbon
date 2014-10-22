#!/usr/bin/env python
import sys
import random

LENGTH = 20
NUM = 1000

def _print_cut_ribbon(l):
   result = ""
   for cand in l:
      result += str(cand) + " "
   return result.strip()

def _main(args):
   for x in xrange(0, NUM):
      ribbonCuts = []
      length = random.randint(1, LENGTH+1)
      ribbonCuts.append(length)
      i = 0
      while i < 3:
         cut = random.randint(1, length+1)
         ribbonCuts.append(cut)
         i += 1
      sys.stdout.write(_print_cut_ribbon(ribbonCuts)+"\n")

if __name__ == "__main__":
   retCode = _main(sys.argv[1:])
   sys.exit(retCode)
