time "--verbose"  "./philoThread" > /dev/null &
sleep "5"
killall "philoThread"
time "-v" "./launcher" > /dev/null &
sleep "5"
killall "launcher"
