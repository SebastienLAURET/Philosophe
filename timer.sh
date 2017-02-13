time ./philoThread 1> /dev/null &
sleep 5
killall philoThread
time ./launcher 1> /dev/null &
sleep 5
killall launcher
