.. _ch-GettingStarted:

Getting Started
###############

Before starting to develop your Hildon applications you need to get and properly install and configure a Maemo SDK. You can download and learn how to use the latest SDK in `Maemo SDK Releases <Maemo SDK Releases>`_ .

To begin our introduction to Hildon, we will start with the simplest program possible. This program creates a window and has no way of exiting except to be killed by using the shell.

Simple Hildon program
=====================

.. literalinclude:: _static/examples/hildon-simplest-example.py

To run the program you can use:

::

    python2.5 base.py


All programs will import  hildon which declares the variables, functions, structures, etc. that will be used in your Hildon application.

The next two lines of code create and display a window.

::



    window = hildon.Window()
    window.show()


The hildon.Window used in this example represents a top-level window in the Hildon framework. It is derived from gtk.Window and provides additional commodities specific to the Hildon framework.

In very simple applications, hildon.Window could be enough. However, in most of the applications a hildon.StackableWindow should be used. Next chapters will clarify this.

The show() shows the widget (makes it visible) that would not be otherwise displayed.

The last line enters the GTK+ main processing loop.

::

    gtk.main();


This call can be found in every GTK+ application and therefore, in every Hildon application. When control reaches this point, GTK+ will sleep waiting for X events (such as button or key presses), timeouts, or file IO notifications to occur. In our simple example, however, events are ignored.

Hello World in Hildon
*********************

To begin our introduction to Hildon, we introduce the classic Hello World, Hildon style. This program will create a window with a widget (a button).

.. _hello-world-example:

Hildon Hello World program
==========================

.. literalinclude:: _static/examples/hildon-hello-world.py

Running Hello World
*******************

To run use:

::

    python2.5 hello-word.py


Stepping Through Hello World
****************************

In this section, the Hello World example above will be explained step by step.

The following lines define the callback function that will be called when the button is "clicked". We ignore both the widget and the data in this example, but usually developers would need to do things with them.

::

    def hello(widget, data):
    	print "Hello World!"


Here starts the definition of the main function like it is usually done in programs written in Python.

::

    if __name__ == "__main__":
        main()


Before using Hildon, it is needed to import it. This import connects to the window system display.

::

    import hildon


Only one HildonProgram can be created per process. Therefore, it should be accessed with hildon_program_get_instance().

::

    program = hildon.hildon_program_get_instance()


In this simple example a new hildon.Window is created. In cases with nested views, a hildon.StackableWindow should be used. Next sections will clarify this topic.

::

    window = hildon.Window()


This call registers a window as belonging to the program. This allows to apply program-wide settings to all the registered windows, such as assigning a common menu to all the registered windows by setting it to the program.

::

    program.add_window(window)


The following code is an example of connecting a signal handler to an object, in this case, the window. The function gtk.main_quit() is set as a handler to the "delete_event" signal. This function tells GTK+ that it must exit from gtk.main() when control is returned to it, making the program terminate.

::


    window.connect("delete_event", gtk.main_quit)


This call creates a new hildon.Button. This button allows to set two labels, one main label and another secondary one. It is also possible set the size of the button and how the labels will be arrange. Notice that you can use gtk.Button's in Hildon applications in case you don't need those additional features.

::

    button = hildon.Button(gtk.HILDON_SIZE_AUTO, hildon.BUTTON_ARRANGEMENT_VERTICAL, "Hello world!")


Here a signal handler is attached to the newly created button so when it emits the "clicked" signal, our hello() function is called. The data is ignored, so we simply pass in NULL to the hello() callback function. Obviously, the "clicked" signal is emitted when the button is pressed.

::

    button.connect("clicked", hello, None)


This is a packing call. It simply tells GTK+ that the button is to be placed in the window where it will be displayed. Only Hildon containers will be deeply explained in this tutorial, so it is highly recommended to read the Packing Widgets section of the `GTK+ 2.0 Tutorial <GTK+ 2.0 Tutorial>`_ .

::

    window.add(button)


Once everything is set up, with all signal handlers in place and the button placed in the window, we ask GTK to "show" the widgets on the screen.

::

    window.show_all()

And of course, we call gtk_main() which waits for events to come from the X server and will call on the widgets to emit signals when these events come.

::

    gtk.main()

