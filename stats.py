

# paste given data within quotes.
st="399, 300, 300, 306, 398, 312, 331, 321, 438, 301"
tmp = st.split(',');
n=len(tmp)

data=[0]*n
for i in range(n):
    data[i]=float(tmp[i])

print("Given Data:",n,"obsevations")
print(data,"\n")

sq=0
s=0
for d in data:
    s+=d
xbar=s/n

u=3.180 #write the population mean here.
sq2=0
for d in data:
    sq+=(xbar-d)*(xbar-d)
    sq2+=(u-d)*(u-d)

print("Sample Mean:",xbar,sep="\t\t\t")
print("Sample Variance,S^2:",sq/(n-1),sep="\t")
print("Biased Variance,S*^2:",sq/(n),sep="\t")
print("WithU Variance,Su^2:",sq/(n),sep="\t")