.. _ch-GettingStarted:

Getting Started
###############

Before starting to develop your Hildon applications you need to get and properly install and configure a Maemo SDK. You can download and learn how to use the latest SDK in `Maemo SDK Releases <Maemo SDK Releases>`_ .

To begin our introduction to Hildon, we will start with the simplest program possible -- base.c. This program creates a window and has no way of exiting except to be killed by using the shell.

Simple Hildon program
=====================

.. code-block:: python

  
  
  #include <hildon/hildon.h>
  
  int main (int   argc,
            char  **argv)
  {
    GtkWidget *window;
  
    hildon_gtk_init (&argc, &argv);
  
    g_set_application_name ("Simplest example");
  
    window = hildon_window_new ();
    gtk_widget_show  (window);
  
    gtk_main ();
  
    return 0;
  }
  
      
To compile the program you can use:

::

  
  
    gcc base.c `pkg-config hildon-1 --cflags --libs` -o base
  
      
All programs will include hildon/hildon.h which declares the variables, functions, structures, etc. that will be used in your Hildon application.

The next line is necessary in every program:

::

  
  
    hildon_gtk_init (&argc, &argv);
  
    
This function replaces a call to gtk_init() and also initializes the Hildon library. Since this function also performs a call to gtk_init(). It is highly recommended to look at `GTK+ Reference Manual <GTK+ Reference Manual>`_ to know more about GTK+ initialization and arguments that are possible to pass to your application on the command line.

The next two lines of code create and display a window.

::

  
  
    window = hildon_window_new ();
    gtk_widget_show  (window);
  
    
The HildonWindow used in this example represents a top-level window in the Hildon framework. It is derived from GtkWindow and provides additional commodities specific to the Hildon framework.

In very simple applications, HildonWindow could be enough. However, in most of the applications a HildonStackableWindow should be used. Next chapters will clarify this.

The gtk_widget_show() shows the widget (makes it visible) that would not be otherwise displayed.

The last line enters the GTK+ main processing loop.

::

  
  
    gtk_widget_main  ();
  
    
This call can be found in every GTK+ application and therefore, in every Hildon application. When control reaches this point, GTK+ will sleep waiting for X events (such as button or key presses), timeouts, or file IO notifications to occur. In our simple example, however, events are ignored.

Hello World in Hildon
*********************

To begin our introduction to Hildon, we introduce the classic Hello World, Hildon style. This program will create a window with a widget (a button).

.. _hello-world-example:

Hildon Hello World program
==========================

.. code-block:: python

  
  
  #include                                        <hildon/hildon.h>
  
  /* This is a callback function. The data arguments are ignored
   * in this example. More on callbacks . */
  static void hello (GtkWidget *widget,
                     gpointer   data)
  {
    g_print ("Hello World!\n");
  }
  
  int
  main                                            (int argc,
                                                   char **argv)
  {
    HildonProgram *program;
    GtkWidget *window;
    GtkWidget *button;
  
    /* This is called in all Hildon applications. Arguments are parsed
     * from the command line and are returned to the application. */
    hildon_gtk_init (&argc, &argv);
  
    /* Get an instance of HildonProgram. It is an object used to represent
     * an application running in the Hildon framework.               */
    program = hildon_program_get_instance ();
  
    /* create a new hildon window */
    window = hildon_window_new ();
  
    /* Registers a window as belonging to the program */
    hildon_program_add_window (program, HILDON_WINDOW (window));
  
    /* When the window is given the "delete_event" signal (this is given
     * by the window manager, usually by the "close" option, or on the
     * titlebar), we ask it to call the delete_event () function
     * as defined above. The data passed to the callback
     * function is NULL and is ignored in the callback function. */
    g_signal_connect (G_OBJECT (window), "delete_event",
                      G_CALLBACK (gtk_main_quit), NULL);
  
    /* Create a new hildon button with its title label set to "Hello world!",
     * also size and type of arrangement is set */
    button = hildon_button_new_with_text (HILDON_SIZE_AUTO,
                                          HILDON_BUTTON_ARRANGEMENT_VERTICAL,
                                          "Hello world!",
                                          NULL);
  
    /* When the button is given the "clicked" signal, we ask it to call the
     * hello () function as defined above. The data passed to the callback
     * function is NULL and is ignored in the callback function. */
    g_signal_connect (G_OBJECT (button), "clicked",
                      G_CALLBACK (hello), NULL);
  
    /* This packs the button into the window (a GTK+ container). */
    gtk_container_add (GTK_CONTAINER (window),
                       button);
  
    /* The final step is to display this newly created widget
     * and all widgets it contains. */
    gtk_widget_show_all (GTK_WIDGET (window));
  
    /* All GTK+ applications must have a gtk_main(). Control ends here
     * and waits for an event to occur (like a key press or
     * mouse event). */
    gtk_main ();
  
    return 0;
  }
  
  
          
Compiling Hello World
*********************

To compile use:

``gcc hello-world.c `pkg-config hildon-1 --cflags --libs` -o hello``\

This uses the program pkg-config, which can be obtained from `Freedesktop <Freedesktop>`_ . This program reads the .pc which comes with Hildon to determine what compiler switches are needed to compile programs that use Hildon. ``pkg-config hildon-1 --cflags`` will output a list of include directories for the compiler to look in, and ``pkg-config hildon-1 --libs`` will output the list of libraries for the compiler to link with and the directories to find them in. Although they could be used separately as ```pkg-config hildon-1 --cflags```\ and ```pkg-config hildon-1 --libs```, in the above example they were joint as a single instance since it is easier to understand.

.. note:: Note that the type of single quote used in the compile command above is significant.

Stepping Through Hello World
****************************

In this section, the Hello World example above will be explained step by step.

The following lines define the callback function that will be called when the button is "clicked". We ignore both the widget and the data in this example, but usually developers would need to do things with them.

::

  
  
    static void hello( GtkWidget *widget,
                       gpointer   data )
    {
      g_print ("Hello World!\n");
    }
  
      
Here starts the definition of the main function like it is usually done in programs written in C.

::

  
  
  int
  main                                            (int argc,
                                                   char **argv)
  {
  
      
Next code declares pointers to an object of type HildonProgram which represents an application running in the Hildon framework. Pointers to the widgets which will show the application are also declared.

::

  
  
    HildonProgram *program;
    GtkWidget *window;
    GtkWidget *button;
  
      
Before using Hildon, it is needed to initialize it. Initialization connects to the window system display, and parses some standard command line arguments.

::

  
  
    hildon_gtk_init (&argc, &argv);
  
      
Only one HildonProgram can be created per process. Therefore, it should be accessed with hildon_program_get_instance().

::

  
  
    program = hildon_program_get_instance ();
  
      
In this simple example a new HildonWindow is created. In cases with nested views, a HildonStackableWindow should be used. Next sections will clarify this topic.

::

  
  
    window = hildon_window_new ();
  
      
This call registers a window as belonging to the program. This allows to apply program-wide settings to all the registered windows, such as assigning a common menu to all the registered windows by setting it to the program.

::

  
  
    hildon_program_add_window (program, HILDON_WINDOW (window));
  
      
The following code is an example of connecting a signal handler to an object, in this case, the window. The function gtk_main_quit () is set as a handler to the "delete_event" signal. This function tells GTK+ that it must exit from gtk_main when control is returned to it, making the program terminate.

::

  
  
    g_signal_connect (G_OBJECT (window), "delete_event",
                      G_CALLBACK (gtk_main_quit), NULL);
  
        
This call creates a new HildonButton. This button allows to set two labels, one main label and another secondary one. It is also possible set the size of the button and how the labels will be arrange. Notice that you can use GtkButton's in Hildon applications in case you don't need those additional features.

::

  
    button = hildon_button_new_with_text (HILDON_SIZE_AUTO,
                                          HILDON_BUTTON_ARRANGEMENT_VERTICAL,
                                          "Hello world!",
                                          NULL);
        
Here a signal handler is attached to the newly created button so when it emits the "clicked" signal, our hello() function is called. The data is ignored, so we simply pass in NULL to the hello() callback function. Obviously, the "clicked" signal is emitted when the button is pressed.

::

  
    g_signal_connect (G_OBJECT (button), "clicked",
                      G_CALLBACK (hello), NULL);
        
This is a packing call. It simply tells GTK+ that the button is to be placed in the window where it will be displayed. Only Hildon containers will be deeply explained in this tutorial, so it is highly recommended to read the Packing Widgets section of the `GTK+ 2.0 Tutorial <GTK+ 2.0 Tutorial>`_ .

::

  
    gtk_container_add (GTK_CONTAINER (window),
                       button);
  
        
Once everything is set up, with all signal handlers in place and the button placed in the window, we ask GTK to "show" the widgets on the screen.

::

  
    gtk_widget_show_all (GTK_WIDGET (window));
        
And of course, we call gtk_main() which waits for events to come from the X server and will call on the widgets to emit signals when these events come.

::

  
    gtk_main ();
        
And the final return. Control returns here after gtk_main_quit() is called.

::

  
    return 0;
        
