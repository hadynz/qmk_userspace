# Hady's QMK userspace

![Build status](https://github.com/hadynz/qmk_userspace/actions/workflows/build.yml/badge.svg)

This is a QMK "[userspace][1]" for my Kinesis Advantage keyboard firmware -- my 
very first ergo keyboard.

## Local Development

1. Setup qmk development environment: https://docs.qmk.fm/#/newbs_getting_started
2. Link this repository to the qmk directory a keycap folder

```bash
# $PWD is the path to this repository
# Create a symlink of the `keymap` folder into `kinesis` keyboard folder inside qmk directory
ln -s $PWD/keymap ../qmk_firmware/keyboards/kinesis/keymaps/hadynz

# Compile
qmk compile -kb kinesis/stapelberg -km hadynz

# Create (QMK Configurator) JSON file from keymap

```

## Background

### The Keyboard

A Kinesis Advantage 1 keyboard with Cherry MX Brown switches. The keyboard has been 
modified with the ["stapelberg" mod][3]. In other words, the keyboard's original controller 
has been gutted and replaced with a Teensy 2.0++ that runs the feature-rich QMK firmware.

### Building and flashing the firmware

The firmware is automatically built using the QMK CLI that runs on [GitHub Actions][4].

Once built, the firmware is flashed onto the Teensy 2.0++ using the [Teensy Loader][2].

### Layout

I bought my keyboard second hand and have built on top of the previous owner (Uric Marker)'s
layout which was largely inspired by the [Miryoku layout][5].

It currently has the following features:

* Layer 0 -- Colemak DH layout with mirrored home row mods
* Layer 1 -- Windows layer
* Layer 2 -- Numbers layer
* Layer 3 -- Shift symbols layer
* Layer 4 -- Mouse layer

## References:

* https://github.com/caksoylar/qmk_userspace
* https://github.com/filterpaper/qmk_userspace

[1]: https://docs.qmk.fm/#/feature_userspace
[2]: https://www.pjrc.com/teensy/loader.html
[3]: https://michael.stapelberg.ch/posts/2020-07-09-kint-kinesis-keyboard-controller
[4]: https://docs.qmk.fm/#/newbs_building_firmware_workflow?id=add-a-github-action-workflow
[5]: https://github.com/manna-harbour/miryoku
