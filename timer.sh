time -o ./res/thread ./philoThread 1> /dev/null &
sleep 5
killall philoThread
time -o ./res/fork  ./launcher 1> /dev/null &
sleep 5
killall launcher
