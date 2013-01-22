ofxStateMachine
===========
ofxStateMachine is intended to help organise code for complex projects.  Each state is essentially a mini OF app and you can override **setup()**, **update()** and so on in the same way.

Use
===
To use the class, simply create your state classes that inherits from **ofxState**.  The only function that it is necessary to implement is **getName()** (this is what you use to change states)...

```cpp
class MyState : public itg::ofxState<>
{
public:
  string getName();
};
```

Functions that you can override are similar to those in **ofBaseApp** with the addition of **stateEnter()** and **stateExit()** see ofxState.h

In your OF app declare an instance of the state machine...

```cpp
itg::ofxStateMachine<> stateMachine;
```

Add your states to the state machine in your OF app **setup()** and choose your initial state...

```cpp
stateMachine.addState<MyState>();
stateMachine.changeState("mystate");
```

...and your done.  Overridden functions such as **update()**, **mousePressed()** and so on in the current state will be called automatically.

Shared Data
===========
If you wish to share data between states then pass your data class as a parameter to both your states and the state machine...

```cpp
itg::ofxStateMachine<MySharedData> stateMachine;
```

```cpp
class MyState : public itg::ofxState<MySharedData>
```

To access shared data from within a state simple call **getSharedData()**...

```cpp
void MyState::update()
{
  getSharedData().doStuff();
}
```

...it can also be accessed from the state machine by calling...

```cpp
stateMachine.getSharedData();
```
Changing States
===============
Changing states is as simple as calling...

```cpp
changeState("mystate");
```

...from within a state.

Pre 0071
========
If you are using a version of OF that is older than 0071, you will need to checkout an older version of the addon.  Run the following command in the directory that you clone the addon to...

```bash
git checkout a9b94a9bb65389478c8ceb268dc98bcec2d46699
``` 
