print("**Welcome to the Binary Adder**")
print("\n")

input1 = "yes"
while input1 =="Yes" or input1 =="yes":
    output = False
    while output == False:
        try:
            H=int(input("Please enter the first number: "))
            if H>255:
                print("The number should be in range of 0 and 255")
            else:
                output = True
        except:
            print("Please Enter a valid input!")
    output = False
    while output == False:
        try:
            N= int(input("Please enter the second number: "))
            if N>255:
                print("The number must be in range of 255: ")
            else:
                output= True
        except:
            print("please input a valid number!")
        print("The binary value of {}is:{}\n".format(H,binary_conversion(H)))
        print("The binary value of {}is:{}\n".format(N,binary_conversion(N)))
              
        Y=binary_conversion(H)
        Z=binary_conversion(N)
        sum1= binaryAdder(str(Y),str(Z))
        print("The sum of {} and {} is:{}\n".format(H,N,sum1))
        Input= input("Do you want to continue? yes/no:")
def binaryConversion(n):
    bit=[] 
    Binary_Number=""
    
    counter=0
    while counter!=8:
        reminder=n%2
        bit.append(reminder)
        n=n//2
        counter=counter+1
    return bit

def reverse(bit):
    Binary=[]
    Binary_Number=""
    for i in range(len(bit)-1,-1,-1):
        Binary.append(bit[i])
        BinNumber=Bin_Number+str(bit[i])
    return Bin_Number
#not gate
def not_gate(y):
    if Y==0:
        return '1'
    else:
        return '0'
    
#xor gate
def xor_gate(Y,Z):
    Y1 = and_gate(Y, not_gate(Z))
    Z1 = and_gate(Z, not_gate(Y))
    return int(or_gate(Y1,Z1))

#and gate
def and_gate(Y,Z):
    if (Y=='1' and Z=='1'):
        return '1'
    else:
        return '0'

#or gate
def or_gate(Y,Z):
    if(Y==Z=='0'):
        return '0'
    else:
        return '1'


    
#byte adder
#def binaryAdder(Y,Z):
    str1=str(binaryNumber1)
    str2=str(binaryNumber2)

def XYZ(binaryNumber1,binaryNumber2):
#converting binarynumber to string
    

#converting to 8 digit bytes
    for i in range(0,(8 - len(str1)),+1) :
        str1= 0+ str1

    for i in range(0,(8 - len(str2)),+1) :
        str2= 0+ str2


    _sum1=''
    carry='0'

    for i in range (7,-1,-1):
        Y,Z=str1[i],str2[i]
        _sum1= _xor(xor(X,Y),_and(_xor(Y,Z),carry))

        if(carry==0):
            return_sum
        else:
             print("sorry,sum is too much huge for stored in byte")
        
#Byte Adder('1','1')                


Loop=True
while Loop==True:
    
    stringfirst=False
    while stringfirst==False:    
        try:
            binaryNumber1=int(input("Enter the decimal number first:"))
            binaryNumber1=valid(binaryNumber1)
            print("\n")
            stringfirst=True
        except:
            print("Invalid Input!")
            print("\n")
            print("please enter int value")
    stringsecond=False
    while stringsecond==False:
        try:
            binaryNumber2=int(input("Enter the decimal number second:"))
            binaryNumber2=valid(binaryNumber2)
            print("\n")
            stringsecond=True
        except:
            print("Invalid Input!")
            print("\n")
            print("please enter int value")
    reversefirst=binaryConversion(binaryNumber1)
    reversesecond=binaryConversion(binaryNumber2)

    first=reverse(reversefirst)
    second=reverse(reversesecond)
    XYZ(first,second)
    result = XYZ(first,second)

#MainClass()
    print("Binary Conversion of initial number is :",initial)
    print("Binary conversion of fianl number is :",final)
    print("\n")
    try:
        q=int(input("Do you want to continue and Do you want to leave:"))
        if q==yes:
            print()
            print("continueing----")
        else:
            print("Thank u for using byte adder :)")
            break
    except:
            print("thank u for using byte adder:)")
            break
    
    
    
    

    








       
