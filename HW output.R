#sse values for subsets
PRESSx1x2x3 #72.56592
adjrx1x2x3 #0.5533241
AICx1x2x3 #213.573
BICx1x2x3 #221.2211
Cx1x2x3 #4

PRESSx0 #151.5576
adjrx0 #0
AICx0 #251.028
BICx0 #252.94
Cx0 #61.69924

PRESSx1 #144.8458
adjrx1 #0.05622845
AICx1 #249.1035
BICx1 #252.9275
Cx1 #55.41814

PRESSx2 #146.7549
adjrx2 #0.06569741
AICx2 #248.5993
BICx2 #252.4234
Cx2 #54.4006

PRESSx3 #157.7792
adjrx3 #0.9995765
AICx3 #252.8313
BICx3 #256.6553
Cx3 #3.020506

PRESSx1x2 #139.8051
adjrx1x2 #0.9996335
AICx1x2 #246.5523
BICx1x2 #252.2883
Cx1x2 #2.614041

PRESSx1x3 #71.75285
adjrx1x3 #0.5459272
AICx1x3 #213.4695
BICx1x3 #219.2056
Cx1x3 #1.348837

PRESSx2x3 #152.0669
adjrx2x3 #0.05153173
AICx2x3 #250.299
BICx2x3 #256.0351
Cx2x3 #2.817453

#highest adjrx1x2x3 #0.5533241
#lowest AICx1x3 213.4695
#lowest BICx1x3 219.2056
#lowest Cx1x3 1.348837
#lowest PRESSx1x3 71.75285
AICx1 #249.1035
BICx1 #252.9275
AICx3 #252.8313
BICx3 #256.6553

plot(1:5, c(AICx0,AICx2,AICx1x2, AICx2x3,AICx1x2x3), type='l', ylim=c(200,300))
lines(x=1:5, y=c(BICx0,BICx2,BICx1x2,BICx2x3, BICx1x2x3), col='red')

#smallest p = 4
#x1x2x3 = 61.03573
#smallest p = 3
#x1x3 = 63.39532
#smallest p = 2
#x2 = 133.2179
#smallest p = 1
#none = 145.5559
#adjr2 not lowest
#aic, bic, cp x1x3

PRESSx0 #151.5576
adjrx0 #0
AICx0 #251.028
BICx0 #252.94
Cx0 #61.69924

PRESSx2 #146.7549
adjrx2 #0.06569741
AICx2 #248.5993
BICx2 #252.4234
Cx2 #54.4006

PRESSx1x3 #71.75285
adjrx1x3 #0.5459272
AICx1x3 #213.4695
BICx1x3 #219.2056
Cx1x3 #1.348837

PRESSx1x2x3 #72.56592
adjrx1x2x3 #0.5533241
AICx1x2x3 #213.573
BICx1x2x3 #221.2211
Cx1x2x3 #4


head(mydata)
dim(mydata)
attatch(mydata)
length(Y)
Y
Ynew = Y[-1]
n=54
X=cbind(rep(1,n),X1,X2,X3,X4)
dim(X)
Xnew=X[-1] #remove first row
dim(Xnew) #53, 5
betanew.hat=solve(t(Xnew)%*%Xnew)
betanew.hat=solve(t(Xnew)%*%Xnew)%*%t(Xnew)%*%Ynew
betanew.hat 
beta.hat = solve(t(X)%*%X)%*%t(X)%*%Y
beta.hat #estimator using all the observations
X[1,]
sum(X[1,]*betanew.hat)

Ynew=Y[-5] #remove 5th element
Xnew=X[-5,] #remove 5th row

betanew.hat=solve(t(Xnew)%*%Xnew)%*%t(Xnew)%*%Ynew
betanew.hat
X[5,]
sum(X[5,]*betanew.hat) #7.193013
Y[5]-7.193013

#code simpler
Yhat = X%*%beta.hat
H = X%*%solve(t(X)%*%X)%*%t(X)
(Y[5]-Yhat[5])/(1-diag(H)[5])
#rerun with full formula
Y[5]-sum(X[5,]*betanew.hat)
(Y-Yhat)/(1-diag(H))
#proof not required, can ask in OH
#Why does press take so long?

mymodel=lm(Y~.,data=mydata)
summary(mymodel)
mymodel$fitted.value
names(mymodel)
lm.influence(mymodel)$hat #gives us all the diagonal elements of the hat matrix
diag(H) #matches with the above code

mydata = read.table("survival2.txt",header=T)
head(mydata)

model...
summary...
is.factor(mydata[,6]) #TRUE
summary(mydata$frame)
medium.index=which(mydata$frame=="medium")
medium.index #observations of frame = mediums
mydata[1:5]
n=dim(mydata)[1]
X7=rep(0,n)
X7[medium.index]=1 #medium = 1, rest are 0

model0 = lm(Y~1,data=mydata)
model4=lm(Y~.,data=mydata)
summary(model0)
summary(model4)
step(model0, scope = list(lower=model0,upper=modelF),direction="foward")
step(model0, scope = list(lower=model0,upper=modelF),direction="backward")
#starting with none-model, won't go anywhere
step(modelF, scope = list(lower=model0,upper=modelF),direction="foward")
#starting with full model, goes backwards
step(model0, scope = list(lower=model0,upper=modelF),direction="both")

# adjrx1 = 1 - (SSEx1/(n-p2)/(SSTO/(n-1)))
# AICx1 = n*log(SSEx1) + 2*p2
# BICx1 = n*log(SSEx1) + p2*log(n)
# Cx1 = (SSEx1/MSE4) - n + 2*p2
# adjrx1 #0.05622845
# AICx1 #249.1035
# BICx1 #252.9275
# Cx1 #55.41814

# adjrx3 = 1 - (SSEx3/(n-p2)/SSTO/(n-1)) #wrong value
# AICx3 = n*log(SSEx3) + 2*p2
# BICx3 = n*log(SSEx3) + p2*log(n)
# Cx3 = SSEx3 / (n-p2)
# adjrx3 #0.9995765 or -0.01682413
# AICx3 #252.8313
# BICx3 #256.6553
# Cx3 #3.020506

# adjrx1x2 = 1-(SSEx1x2/(n-p3)/(SSTO/(n-1)))
# AICx1x2 = n*log(SSEx1x2) + 2*p3
# BICx1x2 = n*log(SSEx1x2) + p3*log(n)
# Cx1x2 = SSEx1x2 / (n-p3)
# adjrx1x2 #0.1200082
# AICx1x2 #246.5523
# BICx1x2 #252.2883
# Cx1x2 #2.614041

# adjrx2x3 = 1-(SSEx2x3/(n-p3)/(SSTO/(n-1)))
# AICx2x3 = n*log(SSEx2x3) + 2*p3
# BICx2x3 = n*log(SSEx2x3) + p3*log(n)
# Cx2x3 = SSEx2x3 / (n-p3)
# adjrx2x3 #0.05153173
# AICx2x3 #250.299
# BICx2x3 #256.0351
# Cx2x3 #2.817453

# > AIC(modelx0,k=2)
# [1] 199.3207
# > AIC(modelx2,k=2)
# [1] 196.892
# > AIC(modelx1x3,k=2)
# [1] 161.7622
# > AIC(modelx1x2x3,k=2)
# [1] 161.8657

# > BIC(modelx0)
# [1] 203.1448
# > BIC(modelx2)
# [1] 202.6281
# > BIC(modelx1x3)
# [1] 169.4103
# > BIC(modelx1x2x3)
# [1] 171.4258
