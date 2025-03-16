# Hady's QMK userspace

![Build status](https://github.com/hadynz/qmk_userspace/actions/workflows/build.yml/badge.svg)

This is a QMK "[userspace][1]" for both my Kinesis Advantage and Keychron Q2 keyboards firmware

## Local Development

1. Setup qmk development environment: <https://docs.qmk.fm/#/newbs_getting_started>
2. Link this repository to the qmk directory a keycap folder

```bash
# Create a symlink of the `keymap_kinesis` folder into `kinesis` keyboard folder inside qmk directory
ln -s $PWD/keymap_kinesis ../qmk_firmware/keyboards/kinesis/keymaps/hadynz
ln -s $PWD/keymap_keychron_q2 ../qmk_firmware/keyboards/keychron/q2/ansi_encoder/keymaps/hadynz

# Compile
qmk compile -kb kinesis/stapelberg -km hadynz       # Kinesis Advantage keyboard
qmk compile -kb keychron/q2/ansi_encoder -km hadynz # Keychron Q2 keyboard
```

# Create (QMK Configurator) JSON file from keymap

qmk c2json -kb kinesis/stapelberg -km hadynz ./keymap_kinesis/keymap.c > keymap_kinesis.json
qmk c2json -kb keychron/q2/ansi_encoder -km hadynz ./keymap_keychron_q2/keymap.c > keymap_keychron_q2.json

# Render keyma to SVG

keymap parse -c 10 -q keymap.json > kinesis_keymap.yaml
keymap draw kinesis_keymap.yaml > kinesis_keymap.svg

## Flashing Keyboards locally

### Keychron Q2

1. Install and run [QMK Toolbox][6]
2. Compile firmware
3. Open firmware file in QMK Toolbox (usuall in root directory of qmk firmware `qmk_firmware/<keyboard>.bin`)
4. Put the keyboard into bootloader mode (at time of writing this is done by (a) turn ON function layer, (b) pressing both F11+F12)
5. Flash! (Important: Ensure that keyboard is not disconnected until flashing is complete)

## Troubleshooting

### QMK config changes not being applied after successful flashing

I've run into this issue sporadically before. When this happens, what has helped is the following:

1. Use physical reset button on the keyboard to turn on DFU mode
2. Flash the keyboard's original firmware again before flashing my custom firmware
3. Clearing all build artifacts by running `qmk clean` in BOTH `qmk_firmware` and `qmk_userspace` directories

For the Keychron Q2, the original firmware can be found [here][6].

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

- Layer 0 -- Colemak DH layout with mirrored home row mods
- Layer 1 -- Windows layer
- Layer 2 -- Numbers layer
- Layer 3 -- Shift symbols layer
- Layer 4 -- Mouse layer

## References

- <https://github.com/caksoylar/qmk_userspace>
- <https://github.com/filterpaper/qmk_userspace>

[1]: https://docs.qmk.fm/#/feature_userspace
[2]: https://www.pjrc.com/teensy/loader.html
[3]: https://michael.stapelberg.ch/posts/2020-07-09-kint-kinesis-keyboard-controller
[4]: https://docs.qmk.fm/#/newbs_building_firmware_workflow?id=add-a-github-action-workflow
[5]: https://github.com/manna-harbour/Miryoku
[6]: https://keychron.com.au/blogs/archived/how-to-factory-reset-or-flash-firmware-for-your-keychron-q2-keyboard
