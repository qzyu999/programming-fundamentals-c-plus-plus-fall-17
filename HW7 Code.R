#Set the working directory
setwd("C:/Users/jyqq9/Desktop/STA 108/HW7")

#Read in the data from the text file
mydata = read.table("HW7Q2.txt", header=T)

#Examine the data
head(mydata)
dim(mydata)
n = length(mydata$Y)
n

#Create basic variables
Y = mydata$Y #Y
SSTO = sum((Y-mean(Y))^2) #SSTO

#b Among the first-order models, report the "best" models according to each of the following
#criteria Ra^2, AICp, BICp, Cp, PRESSp, as well we their corresponding values according to
#the criterion.

#X1, X2, X3
p4 = 4 # number of predictors
modelx1x2x3 = lm(Y~., data = mydata)
SSEx1x2x3 = sum(modelx1x2x3$residuals^2)
MSE4 = (SSEx1x2x3/(n-p4))
adjrx1x2x3 = 1 - (SSEx1x2x3/(n-p4))/(SSTO/(n-1))
AICx1x2x3 = n*log(SSEx1x2x3) + 2*p4
BICx1x2x3 = n*log(SSEx1x2x3) + p4*log(n)
Cx1x2x3 = (SSEx1x2x3/MSE4) - (n-2*p4)
PRESSx1x2x3 = sum(modelx1x2x3$residuals^2/(1-influence(modelx1x2x3)$hat)^2)
PRESSx1x2x3 #72.56592
adjrx1x2x3 #0.5533241
AICx1x2x3 #213.573
BICx1x2x3 #221.2211
Cx1x2x3 #4

#{0} 'X0' *
p1 = 1 # number of predictors
modelx0 = lm(Y~1, data = mydata)
SSEx0 = sum(modelx0$residuals^2)
adjrx0 = 1 - (SSEx0/(n-p1)/(SSTO/(n-1)))
AICx0 = n*log(SSEx0) + 2*p1
BICx0 = n*log(SSEx0) + p1*log(n)
Cx0 = (SSEx0/MSE4) - (n-2*p1)
PRESSx0 = sum(modelx0$residuals^2/(1-influence(modelx0)$hat)^2)
PRESSx0 #151.5576
adjrx0 #0
AICx0 #251.028
BICx0 #252.94
Cx0 #61.69924

#X1
p2 = 2 # number of predictors
modelx1 = lm(Y~X1, data = mydata)
SSEx1 = sum(modelx1$residuals^2)
PRESSx1 = sum(modelx1$residuals^2/(1-influence(modelx1)$hat)^2)
PRESSx1 #144.8458

#X2
modelx2 = lm(Y~X2, data = mydata)
SSEx2 = sum(modelx2$residuals^2)
adjrx2 = 1 - (SSEx2/(n-p2)/(SSTO/(n-1)))
AICx2 = n*log(SSEx2) + 2*p2
BICx2 = n*log(SSEx2) + p2*log(n)
Cx2 = (SSEx2/MSE4) - (n-2*p2)
PRESSx2 = sum(modelx2$residuals^2/(1-influence(modelx2)$hat)^2)
PRESSx2 #146.7549
adjrx2 #0.06569741
AICx2 #248.5993
BICx2 #252.4234
Cx2 #54.4006

#X3
modelx3 = lm(Y~X3, data = mydata)
SSEx3 = sum(modelx3$residuals^2)
PRESSx3 = sum(modelx3$residuals^2/(1-influence(modelx3)$hat)^2)
PRESSx3 #157.7792

#X1, X2
p3 = 3 #number of predictors
modelx1x2 = lm(Y~X1+X2, data = mydata)
SSEx1x2 = sum(modelx1x2$residuals^2)
PRESSx1x2 = sum(modelx1x2$residuals^2/(1-influence(modelx1x2)$hat)^2)
PRESSx1x2 #139.8051

#X1, X3
modelx1x3 = lm(Y~X1+X3, data = mydata)
SSEx1x3 = sum(modelx1x3$residuals^2)
adjrx1x3 = 1-(SSEx1x3/(n-p3)/(SSTO/(n-1)))
AICx1x3nlogn = n*log(SSEx1x3) + 2*p3 - n*log(n)
AICx1x3 = n*log(SSEx1x3) + 2*p3
BICx1x3nlogn = n*log(SSEx1x3) + p3*log(n) - n*log(n)
BICx1x3 = n*log(SSEx1x3) + p3*log(n)
Cx1x3 = (SSEx1x3/MSE4) - (n-2*p3)
PRESSx1x3 = sum(modelx1x3$residuals^2/(1-influence(modelx1x3)$hat)^2)
PRESSx1x3 #71.75285
adjrx1x3 #0.5459272
AICx1x3nlogn #17.86835
AICx1x3 #213.4695
BICx1x3nlogn #23.60442
BICx1x3 #219.2056
Cx1x3 #3.778322

#X2, X3
modelx2x3 = lm(Y~X2+X3, data = mydata)
SSEx2x3 = sum(modelx2x3$residuals^2)
PRESSx2x3 = sum(modelx2x3$residuals^2/(1-influence(modelx2x3)$hat)^2)
PRESSx2x3 #152.0669

# > SSEx0 <- choose this for p = 1
# [1] 145.5559
# > SSEx1
# [1] 134.5681
# > SSEx2 <- choose this for p = 2
# [1] 133.2179
# > SSEx3
# [1] 144.9843
# > SSEx1x2
# [1] 122.8599
# > SSEx1x3 <- choose this for p = 3
# [1] 63.39532
# > SSEx2x3
# [1] 132.4203
# > SSEx1x2x3 <- choose this for p = 4
# [1] 61.03573

#highest adjusted R^2 is x1x2x3 0.5533241
#lowest AICp is x1x3 213.4695
#when subtracting n*log(n) it is 17.86835
#lowest BICp is x1x3 219.2056
#when subtracting n*log(n) 23.60442
#lowest Cp is x1x3 3.778322
#lowest PRESSp is x1x3 71.75285

#part c
#none-model
library(MASS)
#Forward stepwise procedure
fs1=stepAIC(modelx0, scope=list(upper=lm(Y~.,data=mydata), lower=~1), direction="both", k=2)
#Y~X1+X3
#AIC = 17.87

#Forward selection procedure
fs1=stepAIC(modelx0, scope=list(upper=lm(Y~.,data=mydata), lower=~1), direction="forward", k=2)
#Y~X2+X1+X3
#AIC = 17.97