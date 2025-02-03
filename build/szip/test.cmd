szip -b1 %1 %1.sz
szip -d %1.sz | check %1 logfile
del %1.sz
