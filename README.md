# Pokémon Trinity

**Hoenn → Johto → Kanto, as one continuous story.**
Three full regions, three leagues, 24 badges, one villain behind all of it.

Pokémon Trinity is a Game Boy Advance ROM hack built on Pokémon Emerald
(via [pokeemerald-expansion](https://github.com/rh-hideout/pokeemerald-expansion)).
You start in Hoenn, and when you beat the Hoenn League the game doesn't end. You
sail to Johto, then Kanto, and finish at the Indigo Plateau against Champion Ash.
Red is waiting at the top of Mt. Silver after that.

> This repository is the game's **source code**. It does not contain a ROM.
> See [Building the game](#building-the-game) to make one yourself.

---

## The story

A shadowy financier known only as **"G"** has been funding both Team Aqua and
Team Magma to keep Hoenn unstable. Following that trail takes you across three regions.

| Act | Region | Badges | What happens |
|-----|--------|--------|--------------|
| **I** | **Hoenn** | 1–8 | Emerald's Aqua/Magma war, with documents and defeated admins pointing to "G". Beat the Hoenn League, then board the S.S. Tidal to Johto. |
| **II** | **Johto** | 9–16 | The Team Rocket revival: Slowpoke Well, Lake of Rage, the Radio Tower takeover. The Radio Tower reveals that G is **Giovanni**. First trip to the Indigo Plateau, where Lance is Champion. |
| **III** | **Kanto** | 17–24 | Giovanni has taken Viridian Gym back by force and is rebuilding Team Rocket underneath it. Clear the other seven gyms, raid the Rocket Hideout and stop his Mewtwo capture rig. Badge 24 comes from beating him. |
| **Finale** | Indigo Plateau → Mt. Silver | — | The Elite Four has a new lineup for your second visit. Beat **Champion Ash** to roll the credits. Then climb Mt. Silver to face **Red**. |

After the credits, a post-game tour lets you find **Mewtwo, Mew, Celebi,
Jirachi and Deoxys**, plus rematches and wrap-ups for the rivals.

### Characters you'll keep meeting

- **Your friend crew.** Six trainers who keep turning up in all three regions
  (Harjot, Ivraj, Sumeet, Prabhjit, Gurnav and Bobby). Each rematch is harder than the last.
  Bobby is hiding something, and after a certain point he calls you on the PokéNav at each
  story beat to tell you where to go next.
- **Rivals.** May/Brendan in Hoenn and again in Kanto. Silver, Giovanni's son, in
  Johto and Kanto. Wally, who follows you all the way to the final league.
- **Champion Ash.** You never meet him before the fight. His Pikachu is level 100.

## What's in the game

- **Three complete, walkable regions.** Hoenn comes from Emerald. Johto is rebuilt from
  the Gold/Silver/Crystal maps and Kanto from FireRed/LeafGreen, all linked up
  as one world.
- **24 gyms and three leagues.** The Johto leaders are rebuilt with full teams
  that match their reputations. The Kanto leaders are veterans with teams of 5–6.
- **Nine starters.** You pick one Pokémon from any of the Kanto, Johto or Hoenn starter trios.
- **The original 386 Pokémon** (Generations 1–3) in the wild.
- **Modern battle rules.** Physical/special split, the Fairy type, updated moves
  and abilities, and reusable TMs. The game leaves out Mega Evolution, Z-Moves,
  Dynamax and Terastallization, so bosses are tough because of their teams, not gimmicks.
- **Exp. Share for the whole party** is on from the start, so your team keeps up
  across a long three-region game.
- **Wild levels that match each region.** Johto and Kanto wild Pokémon are set to
  about 90% of the local trainers' levels, so they're worth training on when you
  arrive. You can still catch every species.
- **Real FireRed sprites and dialogue in Kanto.** Kanto's leaders and trainers use their original art and lines.
- **A sea route between Lilycove and Vermilion**, so Hoenn and Kanto connect directly.

### Level curve

| Stretch | Roughly |
|---------|---------|
| Hoenn League | ~58 |
| Johto gyms → Champion Lance | ~60 → 77 |
| Kanto gyms → Giovanni | ~76 → 88 |
| Elite Four (second visit) → Champion Ash | ~88 → 92 |
| Red, Mt. Silver | 98–100 |

## Building the game

You build the ROM from this source. It uses the same toolchain as
pokeemerald-expansion.

1. Install the toolchain for your OS by following [INSTALL.md](INSTALL.md)
   (Windows via WSL, macOS or Linux; it covers devkitARM and the other requirements).
2. Clone this repository and build:

   ```sh
   git clone https://github.com/jps7878/pokemontrinity.git
   cd pokemontrinity
   make -j$(nproc)          # on macOS: make -j$(sysctl -n hw.ncpu)
   ```

3. The output is `pokeemerald.gba`. It's a normal 32 MB GBA ROM.

For reference, the v1.0 build should produce a ROM with this SHA-256:
`f3cb2e3bac874df7254d4112d3e039b851b8170c9114c1414ccc5957388f836d`

## Playing

- Open the ROM in any GBA emulator. It has been tested on **mGBA** and
  **VisualBoyAdvance-M**. Play it like a normal Pokémon game.
- Start a **new save**. Saves from vanilla Emerald or other hacks won't work.
- The Key Items pocket has 30 slots. It's a hard limit of the save format, so don't
  hoard key items you've finished with.

## Known limitations

- **Fly only works in Hoenn.** To travel between regions, use the S.S. Tidal
  (Slateport ↔ Olivine) or the Lilycove ↔ Vermilion sailing.
- **Some characters share a sprite.** Janine and Karen, Petrel and Proton, and Morty
  and Will look alike. These characters have no GBA-era sprites of their own.
- **Route 23 and Victory Road stay around level 66.** You walk them twice, and
  the first time is part of the Johto league run, so they're deliberately kept low.

## Credits

- **Created by Jaspal Singh with [Claude Code](https://claude.com/claude-code).**
- Built on [pokeemerald-expansion](https://github.com/rh-hideout/pokeemerald-expansion)
  by the ROM Hacking Hideout community and its contributors (see [CREDITS.md](CREDITS.md)).
- Johto and Kanto were ported from the [pret](https://github.com/pret) decompilations of
  Pokémon Crystal (`pokecrystal`) and FireRed (`pokefirered`).

## Disclaimer

Pokémon Trinity is a non-commercial fan project. It is not affiliated with,
endorsed by or sponsored by Nintendo, Game Freak, Creatures Inc. or
The Pokémon Company. Pokémon and all related names are trademarks of their
respective owners. This repository contains no ROM files. Do not use it to
distribute copyrighted ROMs.
