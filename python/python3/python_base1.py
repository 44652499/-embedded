#!/usr/bin/python3
# print("hello world");
# a=30;
# b=20;
# print(a+b);
# print(abs(-2000))
#[root@localhost ~]# pydoc -p 8001   //start python helo doc service
#pydoc server ready at http://localhost:8001/

# name=input("please input your name:")
# print("hello",name);

# print(3+2);
# print(3-2);
# print(3*2);
# print(3**2);
# print(3/2);
# print(3//2);
# print(3%2);

# width=20;
# height=30;
# print(width*height-3+2//5);

# print(3*1.75-2+3)

# tax=12.345;
# price=tax*20;
# print(price*tax);
# price +  _
# print(price)

# name='kimi';
# print(name);
# print('kimi\'ok');
# print("kimi'ok");
# print('"hello kimi" study');
# print("\"hello kimi\" study");

# print('''/
#   Usage: thingy [OPTIONS]
#      -h                        Display this usage message
#      -H hostname               Hostname to connect to
# ''')
#print(3*'au'+'hello')
#print('py''thon');

# print('Display this'
#       'usage message')

word="python";
# print(word[0]);
# print(word[1]);
# print(word[5]);
# print(word[-1]);
# print(word[-2]);
# print(word[-6]);
# print(word[0:2]);
# print(word[4:10]);
# print(word[:2]+word[2:]);
# print(word[:2]);
# print(word[2:]);
# print(word[:2]+'pp');
# s="123456789";
# print(len(s));

#squares = [1, 4, 9, 16, 25];
#print(squares);

# squares = [1, 4, 9, 16, 25]
# print(squares[0]);
# print(squares[-1]);
# print(squares[-3:]);
# print(squares[-5:]);
# squares[3]=3**4;
# print(squares[:]);
# print(len(squares));
# squares.append(900);
# print(squares);

# letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g'];
# letters[2:5] = ['C', 'D', 'E']
# letters[2:5] = []
# letters[:]=[]
# print(letters);
# print(len(letters))

# a = ['a', 'b', 'c']
# n = [1, 2, 3]
# x = [a, n]
# print(x)
# print (x[0])
# print(x[0][1])
# a,b=0,1
# while b<10:
#  print(b)
#  a,b=b,a+b

# a,b=0,1
# while b<100:
#     print(b,end=',')
#     a,b=b,a+b
#
# x=int(input("please input integer:"))
# if x<0:
#     x=0
#     print('Negative changed to zero')
# elif x==0:
#     print('zero')
# elif x==1:
#     print('Single')
# else:
#     print('more')

# words = ['cat', 'window', 'defenestrate']
# for w in words:
#     print(w,len(w))

# words = ['cat', 'window', 'defenestrate']
# for w in words[:]:
#     if len(w)>6:
#         words.insert(0,w)
# print (words)


# for i in range(5):
#     print(i)

# for i in range(5,10):
#     print(i)
#
# for i in range(0,10,3):
#     print(i)
#
# for i in range(-1,-10,-3):
#     print(i)

# a = ['Mary', 'had', 'a', 'little', 'lamb']
# for i in range(len(a)):
#     print(a[i])

# print(range(10))

# print(list(range(10)))

# for n in range(2, 10):
#     for x in range(2, n):
#         if n % x == 0:
#             print(n, 'equals', x, '*', n//x)
#             break
#     else:
#         print(n, 'is a prime number')

for num in range(2,10):
    if num % 2 == 0:
        print("Found an event number",num)
        continue
    print('Found a number',num)