#!/bin/bash
for file in *widget
do 
	echo $file
	cd $file 
	qmake
	make clean
	make
	cd ..
done

#!/bin/bash
for file in *plugin
do 
	echo $file
	cd $file
	qmake
	make clean
	make
	cd ..
done
