#!/usr/bin/python
#encoding=utf-8
"""
counter =100
miles=1000.34
name="字符串"

print counter
print miles
print name
"""
'''
a=b=c=1
print a
print b
print c
a,b,c=1,2,"John"
print a
print b
print c
'''
'''
str="Hello World!"
print str
print str[0]
print str[2:5]
print str[2:]
print str*2
print str+"test"
'''
#列表集合
# list=['runoob',789,2.23,70.2]
# tinylist=[123,'john']
# print list  输出所有列表值
# print list[0] 输出列表第二个值
# print list[1:3] 输出列表第二个值到第三个值(3为开区间,闭区间是3-1)
# print list[2:]
# print tinylist*2
# print list+tinylist

#只读列表
# tuple=('runoob',786,2.23,'john',70.2)
# tynituple=(123,'john')
# print tuple
# print tuple[0]
# # print tuple[1:4]
# # print tuple[2:]
# # print tynituple*2
# # print tuple+tynituple
# tuple[0]='123123213'
# print tuple[0]

dict={}
dict['one']="this is one"
dict[2]="this is two"
tinydict={'name':'john','code':6734,'dept':'sales'}
print dict['one']
print dict[2]
print tinydict
print tinydict.keys()
print tinydict.values()
