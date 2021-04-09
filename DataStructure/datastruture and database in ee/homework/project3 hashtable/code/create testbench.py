f = open('autobuild.cpp','w')

for i in range(1,100):
    # print("cout << \"insert Entry("+ str(i) +","+str(i*11)+")...\" << endl;")
    f.write("pTable->insert(Entry("+str(i)+","+str(i*11)+"));"+'\n')
f.close
