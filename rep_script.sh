#!/bin/bash



echo "This script will be used to transform PIVX into another Cryptocurrency"
echo -n "Enter the  name of the coin:"
read name
echo -n "Enter the name in lowercast:"
read lname
echo -n "Enter the initials of the coin:"
read cname
echo -n "Main net port:"
read mainport
echo -n "Test net port:"
read testnet
echo -n "RPC main port:"
read rpcmain
echo -n "RPC Test port:"
read rpctest
echo -n "Reg Test port1:"
read regtestone
echo -n "Reg Test port2:"
read regtesttwo
echo -n "Example port:"
read exampleport
echo "Thanks, making changes"

mkdir $lname
cd $lname
git clone https://github.com/gjhiggins/diproton
cd diproton
git checkout flibbertygibbert


find . -type f -print0 | xargs -0 sed -i "s/pivx/${lname}/g; s/PIVX/${name}/g; s/2015-2018 ${name}/2015-2018 PIVX/g; s/2017-2018 ${name}/2017-2018 PIVX/g; s/2017\-2018 ${name}/2017\-2018 PIVX/g; s/2015\-2018 ${name}/2015\-2018 PIVX/g; s/2016\-2018 ${name}/2016\-2018 PIVX/g; s/2016\-2018 The ${name}/2016\-2018 The PIVX/g; s/2015\-2018 The ${name}/2015\-2018 The PIVX/g; s/2017\-2018 The ${name}/2017\-2018 The PIVX/g"
find . -type f -print0 | xargs -0 sed -i "s/51472 /${mainport} /g; s/:51472 /:${mainport} /g; s/, 51472\"/, ${mainport}\"/g; s/= 51472/= ${mainport}/g; s/ 51472)/ ${mainport})/g; s/1:51472/1:${mainport}/g; s/ 51472, / ${mainport}, /g; s/:51472/$mainport}/gi; s/ 51472 / ${mainport} /g"
find . -type f -print0 | xargs -0 sed -i "s/51474 /${testnet} /g; s/:51474 /:${testnet} /g; s/, 51474\"/, ${testnet}\"/g; s/= 51474/= ${testnet}/g; s/ 51474)/ ${testnet})/g; s/1:51474/1:${testnet}/g; s/ 51474, / ${testnet}, /g"
find . -type f -print0 | xargs -0 sed -i "s/51476 /${regtestone} /g; s/:51476 /:${regtestone} /g; s/, 51476\"/, ${regtestone}\"/g; s/= 51476/= ${regtestone}/g; s/ 51476)/ ${regtestone})/g; s/1:51476/1:${regtestone}/g; s/ 51476, / ${regtestone}, /g"
find . -type f -print0 | xargs -0 sed -i "s/else 51473/else ${rpcmain}/g; s/51473 /${rpcmain} /g; s/:51473 /:${rpcmain} /g; s/, 51473\"/, ${rpcmain}\"/g; s/= 51473/= ${rpcmain}/g; s/ 51473)/ ${rpcmain})/g; s/1:51473/1:${rpcmain}/g; s/ 51473, / ${rpcmain}, /g; s/port=51473/port=${rpcmain}/g; s/'51473'/'${rpcmain}'/g"
find . -type f -print0 | xargs -0 sed -i "s/51475 /${rpctest} /g; s/:51475 /:${rpctest} /g; s/, 51475\"/, ${rpctest}\"/g; s/= 51475/= ${rpctest}/g; s/ 51475)/ ${rpctest})/g; s/1:51475/1:${rpctest}/g; s/ 51475, / ${rpctest}, /g"
find . -type f -print0 | xargs -0 sed -i "s/51478 /${regtesttwo} /g; s/:51478 /:${regtesttwo} /g; s/, 51478\"/, ${regtesttwo}\"/g; s/= 51478/= ${regtesttwo}/g; s/ 51478)/ ${regtesttwo})/g; s/1:51478/1:${regtesttwo}/g; s/ 51478, / ${regtesttwo}, /g"
find . -type f -print0 | xargs -0 sed -i "s/51470 /${exampleport} /g; s/:51470 /:${exampleport} /g; s/, 51470\"/, ${exampleport}\"/g; s/= 51470/= ${exampleport}/g; s/ 51470)/ ${exampleport})/g; s/1:51470/1:${exampleport}/g; s/ 51470, / ${exampleport}, /g; s/=51470/=${exampleport}/g; s/port=51470/port=${exampleport}/g"
find . -type f -print0 | xargs -0 sed -i "s/9009 /${mainport} /g; s/:9009 /:${mainport} /g; s/, 9009\"/, ${mainport}\"/g; s/= 9009/= ${mainport}/g; s/ 9009)/ ${mainport})/g; s/1:9009/1:${mainport}/g; s/ 9009, / ${mainport}, /g"
find . -type f -print0 | xargs -0 sed -i "s/19009 /${testnet} /g; s/:19009 /:${testnet} /g; s/, 19009\"/, ${testnet}\"/g; s/= 19009/= ${testnet}/g; s/ 19009)/ ${testnet})/g; s/1:19009/1:${testnet}/g; s/ 19009, / ${testnet}, /g"
find . -type f -print0 | xargs -0 sed -i "s/19004 /${regtestone} /g; s/:19004 /:${regtestone} /g; s/, 19004\"/, ${regtestone}\"/g; s/= 19004/= ${regtestone}/g; s/ 19004)/ ${regtestone})/g; s/1:19004/1:${regtestone}/g; s/ 19004, / ${regtestone}, /g"
find . -type f -print0 | xargs -0 sed -i "s/9019 /${rpcmain} /g; s/:9019 /:${rpcmain} /g; s/, 9019\"/, ${rpcmain}\"/g; s/= 9019/= ${rpcmain}/g; s/ 9019)/ ${rpcmain})/g; s/1:9019/1:${rpcmain}/g; s/ 9019, / ${rpcmain}, /g"
find . -type f -print0 | xargs -0 sed -i "s/19019 /${rpctest} /g; s/:19019 /:${rpctest} /g; s/, 19019\"/, ${rpctest}\"/g; s/= 19019/= ${rpctest}/g; s/ 19019)/ ${rpctest})/g; s/1:19019/1:${rpctest}/g; s/ 19019, / ${rpctest}, /g"
find . -type f -print0 | xargs -0 sed -i "s/19029 /${regtesttwo} /g; s/:19029 /:${regtesttwo} /g; s/, 19029\"/, ${regtesttwo}\"/g; s/= 19029/= ${regtesttwo}/g; s/ 19029)/ ${regtesttwo})/g; s/1:19029/1:${regtesttwo}/g; s/ 19029, / ${regtesttwo}, /g"
find . -type f -print0 | xargs -0 sed -i "s/9029 /${exampleport} /g; s/:9029 /:${exampleport} /g; s/, 9029\"/, ${exampleport}\"/g; s/= 9029/= ${exampleport}/g; s/ 9029)/ ${exampleport})/g; s/1:9029/1:${exampleport}/g; s/ 9029, / ${exampleport}, /g; s/=9029/=${exampleport}/g"
find . -type f -print0 | xargs -0 sed -i "s/heliumlabs/${lname}/g; s/heliumpay/${lname}/g; s/helium/${lname}/g; s/Helium/${name}/g"

echo "Done making changes"
sleep 5
echo "Running configure to compile - running Linux first"
./autogen.sh
./configure --with-qrencode --with-gui --disable-tests
cp libbitcoinconsensus.pc.in libbitcoinconsensus.pc
echo "Configure successful"
sleep 3
echo "Running make"
make
echo "Make complete"

#sleep 5
#echo "Building Windows client"
#PATH=$(echo "$PATH" | sed -e 's/:\/mnt.*//g')
#cd depends
#make HOST=x86_64-w64-mingw32
#cd ..
#./autogen.sh
#CONFIG_SITE=$PWD/depends/x86_64-w64-mingw32/share/config.site ./configure --with-qrencode --with-gui --disable-tests --prefix=/
#make
#echo "Completed Windows client"
