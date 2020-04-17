#/usr/bin/env python

#twitterbot from www.makeuseof.com/tag/how-to-build-a-raspbery-pi-twitter-bot/

#serial from https://playground.arduino.cc/Interfacing/Python

#punctuation strip from https://stackoverflow.com/questions/265960/best-way-to-strip-punctuation-from-a-string

#tweets to
#SCC Maker Bot
#@sccmakerbot

import sys
from twython import Twython
import serial
import time
import string

CONSUMER_KEY=fill
CONSUMER_SECRET=in
ACCESS_KEY=your
ACCESS_SECRET=own

api=Twython(CONSUMER_KEY,CONSUMER_SECRET,ACCESS_KEY,ACCESS_SECRET)

ids=[]#

def songChoice(api):
    timeline=api.get_mentions_timeline()#gets all of my mentions
    for tweet in timeline:
        #print(tweet['created_at'][-4:])#.keys())
        if tweet['id'] in ids or int(tweet['created_at'][-4:])<2020:
            print ("already ran this")
            return False
        ids.append(tweet['id'])
        #output = "thanks @"+tweet['user']['screen_name']+","
        words=tweet['text'].lower()
        for punc in string.punctuation:
            words=words.replace(punc," ")
        words=words.split()
        if 'waterloo' in words:
            output='W'
        elif 'bingo' in words:
            output='B'
        elif 'old' in words or 'macdonald' in words or 'farm' in words:
            output='M'
        elif 'secret' in words:
            output='S'
        else:#not a command
            output='E' #play error song
        print (words,output)
        return output.encode()#tweet['text'].encode('utf-8')

def readHashtag(api,tag):
    #searches all of twitter
    query=api.search(q=tag)#,result_type='recent')
    #print query
    for result in query['statuses']:
        return result['text'].encode('utf-8')
    return 'tweet to '+tag

def sendToArduino(string):
    ser.write(string)#
    time.sleep(3)


ser = serial.Serial('COM21', 9600)#windows
#ser = serial.Serial('/dev/tty.usbserial', 9600)#linux/mac
#ser = serial.Serial('/dev/ttyACM0', 9600)#raspberryPi
time.sleep(2)#wait for arduino to reset

#api.update_status(status='Trying to become a real twitterbot #sccmakes')


while True:
#if True:
#for x in range(5):
    robotComm=songChoice(api)
    print (ids)
    if robotComm:
        sendToArduino(robotComm)
        #api.update_status(status=robotComm)
    time.sleep(3)
    #GPIO.output(chan_list,GPIO.LOW)
    #sendToArduino(readHashtag(api,'#sccmakes'))
    time.sleep(20)
#sendToArduino('maximum number of characters is 140 I think, what do you think my friend? I think it is hard to write 140 characters sometimes. And yet we are almost there.')
#sendToArduino('arduino interface works!')

time.sleep(2)#wait for string to finish
ser.close()












#works
##timeline=api.get_home_timeline()
###print timeline
##for tweet in timeline:
##    mentions= tweet['entities']['user_mentions']
##    for mention in mentions:
##        print '@',mention['screen_name']
##    hashtags=tweet['entities'].get('hashtags')
##    for hashtag in hashtags:
##        print '#',hashtag['text']
##    #break
