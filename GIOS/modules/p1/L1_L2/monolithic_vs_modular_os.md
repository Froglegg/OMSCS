# Monolithic OS
benefits:
    every possible service is already part of the operating system
    everything is included, everything is packaged
downside:
    lack of customization, portability, manageability, large memory requirement

# Modular OS
E.g., linux operating system
Has a number of basic services and APIs, however, everythihng can be added as a module
You can easily customize which FS, scheduler, etc., that the OS uses
This is possible becasuse the OS specifies interfaces that any module must implement in order to be installed on the operating system
So for example if we had a database application, we could run the FS that is optimized for random access, or if it's some other type of computation, we could run the FS that's optimized for sequential access

Benefits;
- easy to maintain and upgrade
- smaller footprint
- less resrouce needs

Downsides:
- indirection can impact performance (because it has to go through the module interface)
- maintenance can be an issue, disparate code bases can lead to bugs

But overall is better than monolithic OS and is commonly used today