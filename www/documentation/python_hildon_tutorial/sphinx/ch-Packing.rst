.. _ch-Packing:

Navigation
##########

In previous examples only one widget was added to a window so we could simply use a container_add() to "pack" it into the window. To pack more than one widget into a window it is necessary to use container widgets.

To develop Hildon user interfaces, you can use any container widget provided by GTK+. For more details, `GTK+ 2.0 Tutorial <GTK+ 2.0 Tutorial>`_ includes a good introduction to this topic.

Apart from supporting those containers, the Hildon framework also provides a new container widget called HildonPannableArea, a scrolling widget designed for touch screens. This chapter will cover all that is necessary to properly use this widget.

Pannable Area
*************

HildonPannableArea is used to create an area with another widget inside which will be accessible regardless of the size using the touchscreen to scroll it. You may insert any type of widget into a pannable area, and it will be accessible by dragging on the area with the fingers.

This widget can be "panned" (scrolled) in any direction using the touchscreen with the fingers. One remarkable characteristic is that the scrolling is "kinetic", meaning that the motion will continue from the initial motion by gradually slowing down to stop.

The use of this widget is very similar to GTK+ scrolled windows. In fact, both widgets implement a similar concept and its APIs are very similar.

To create a new pannable area you can choose either of the following functions:

::

  
  hildon.PannableArea()
  hildon.hildon_pannable_area_new_full(mode, enabled, vel_min, vel_max, decel, sps)  
      
The first one creates a new pannable area with the properties set to the default values. The second one allows you to set the value of the most important properties of this widget:

* mode : Used to change the behaviour of the pannable area allowing to choose whether to use the "kinetic" effect described above.
* enabled : Enable or disable finger-scroll.
* vel_min, vel_max : Allows developers to adjust how many pixels the child widget will be move per "frame".
* decel : Value for the deceleration property.
* sps : Amount of scroll events to generate per second.

For most applications, default values of these properties will be right and thus, the simpler constructor will be enough. In the Hildon reference manual you can read more about all pannable area's properties.

Once the area is created you can then place your object into the pannable window using the following function.

::

  def add_with_viewport(self, child) 
        
      
That is a convenience function used to add a child to a GtkViewport, and add the viewport to the pannable area.

.. warning:: Widgets that have native scrolling should be added directly inside a pannable area. For example, widgets such as GtkTextView, GtkTreeView, GtkIconView and GtkLayout should be added by calling add(). Otherwise, panning could not work properly.

Pannable area example
*********************

Functions explained above are enough for a simple example. The following example packs a table with 100 toggle buttons into a pannable area.

Example of a pannable area
==========================

.. literalinclude:: ../examples/hildon-pannable-area.py

      
In the example above you can see that the following two calls are enough to use a pannable area. The rest of the code of the example is no different to that used in a GTK+ application.

.. code-block:: python

    # Create a new pannable area.
    pannable_area = hildon.PannableArea()
    # Pack the table into the pannable area
    pannable_area.add_with_viewport(table);
  
          
To see all the buttons, users can scroll with the fingers. In this example, horizontal and vertical panning are activated as that is needed to allow users to be able to interact both all the widgets. The property "mov-mode" controls if the area can scroll horizontally, vertically (default value) or both, using hildon.MOVEMENT_MODE_HORIZ, hildon.MOVEMENT_MODE_VERT or hildon.MOVEMENT_MODE_BOTH, respectively.

Additional features
*******************

Pannable areas provide a set of convenience functions that make it easier to move to a certain element inside the area without users interaction.

These functions allow to scroll or jump to a position which ensures that a certain point or a certain child widget is visible for the user.

For example, the first of the functions changes the current position on the pannable area to ensure position (x,y) is visible. The movement is a quick jump. The second function performs a smoothly scroll towards the selected position.

::

  def jump_to(self, x, y)
  def scroll_to(self, x, y) 
  
      
It is also possible to jump or scroll to a certain descendent of the area using the following functions, the argument should be a reference to a descendent widget.

::

  
  def jump_to_child(self, child) 
  def scroll_to_child(self, child)
  
      
Here is a modified version of the previous example. The pannable area is packed into an gtk.VBox and a new button is also added to navigate to the last clicked button.

Example of a pannable area and a "jump-to" button
=================================================

.. literalinclude:: ../examples/hildon-pannable-area-whith-jump-to-button.py

The example used a global variable to store a reference to the last clicked button. This reference will be used by the callback go_to_last_clicked to jump to it by calling one of the navigation functions. This is the function used as a handler for the signal "clicked" of the button outside the pannable area.

You can test the different navigation functions by just changing the call in the mentioned callback.

When you use the navigation functions that allow to navigate to a certain child, the widget must be already realized. You can check it with gtk.WidgetFlags.realized. If you want to call it during the initialization process you can use the navigation function inside a callback to the "realized" signal.

