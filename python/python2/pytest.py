#!/usr/bin/python
def add(a,b):
	print "in python function add"
	print "a="+str(a)
	print "b="+str(b)
	print "ret="+str(a+b)
	return

def sub(a,b):
	print "in python function sub"
	print "a="+str(a)
	print "b="+str(b)
	print "ret="+str(a-b)
	return
class defineclass:
	def __init__(self):
		print "defineclass init"
	def fun():
		print "defineclass fun"
	def __getitem__(self,id):
		return "get item"
def update():
	obj=defineclass();
	print obj["item1"]