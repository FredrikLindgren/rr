fv = 0
kso = 0x2d4
ksc = 0
smo = 0x2d4
smc = 0
mso = 0x2d4
msc = 0
iso = 0x2d4
ilo = 0x2d4
ilc = 0
elo = 0x2d4
elc = 0
i_0 = 0
off_0 = 0
off_1 = 0
tmp_0 = 0
tmp_1 = 0
SPRINT ks fail
SPRINT sm fail
SPRINT ms fail
SPRINT is fail
SPRINT il fail
SPRINT el fail
READ_BYTE 0x33 fv //EFF version
PATCH_IF fv = 0 BEGIN
  PATCH_INCLUDE ~RR/LIB/fj_cre_eff_v2.tpp~
END
PATCH_IF FILE_EXISTS_IN_GAME ~fw0125.are~ BEGIN //Tutu
  FOR (s1 = 0xa4; s1 < 0x234; s1 += 0x4) BEGIN
    READ_LONG s1 ss //Soundslots
    PATCH_IF ss > 10000000 BEGIN
      WRITE_LONG s1 ~-1~
    END
  END
END
READ_LONG 0x2a0 kso //Known spells offset
READ_LONG 0x2a4 ksc //Known spells count
READ_LONG 0x2a8 smo //Spell memorization info offset
READ_LONG 0x2ac smc //Spell memorization info count
READ_LONG 0x2b0 mso //Memorized spells offset
READ_LONG 0x2b4 msc //Memorized spells count
READ_LONG 0x2b8 iso //Item slot offset
READ_LONG 0x2bc ilo //Item offset
READ_LONG 0x2c0 ilc //Item count
READ_LONG 0x2c4 elo //Effects offset
READ_LONG 0x2c8 elc //Effects count
READ_ASCII kso ks ELSE fail (0xc * ksc)
READ_ASCII smo sm ELSE fail (0x10 * smc)
READ_ASCII mso ms ELSE fail (0xc * msc)
READ_ASCII iso is ELSE fail (0x50)
READ_ASCII ilo il ELSE fail (0x14 * ilc)
READ_ASCII elo el ELSE fail (elc * (0x30 + ((fv & 0x1) = 0x1 ? 0xd8 : 0)))
DELETE_BYTES 0x2d4 SOURCE_SIZE - 0x2d4
off_0 = 0x2d4
WRITE_LONG 0x2a0 off_0
PATCH_IF ~%ks%~ STR_CMP fail BEGIN
  INSERT_BYTES off_0 0xc * ksc
  WRITE_ASCIIE off_0 ~%ks%~
END ELSE BEGIN
  ksc = 0
  WRITE_LONG 0x2a4 ksc
END
off_0 += 0xc * ksc
WRITE_LONG 0x2a8 off_0
INSERT_BYTES off_0 0x10 * 0x11
PATCH_IF ~%sm%~ STR_CMP fail && smc = 0x11 BEGIN
  WRITE_ASCIIE off_0 ~%sm%~
END ELSE BEGIN
  FOR (i_0 = 0; i_0 < 7; i_0 += 1) BEGIN
    WRITE_SHORT off_0 + i_0 * 0x10 i_0
  END
  FOR (i_0 = 0; i_0 < 9; i_0 += 1) BEGIN
    WRITE_SHORT off_0 + i_0 * 0x10 + 0x70 i_0
    WRITE_SHORT off_0 + i_0 * 0x10 + 0x76 1
  END
  WRITE_SHORT off_0 + 0x106 0x2
  PATCH_IF ~%sm%~ STR_CMP fail BEGIN
    PATCH_IF smc > 0x11 BEGIN
      msc = 0
      SPRINT ms fail
    END ELSE PATCH_IF smc < 0x11 && smc > 0 BEGIN
      PATCH_IF STRING_LENGTH EVALUATE_BUFFER ~%sm%~ = 0x10 * smc BEGIN
        smc = 0x11
        WHILE STRING_LENGTH EVALUATE_BUFFER ~%sm%~ > 0 BEGIN
          off_1 = 0
          INNER_PATCH_SAVE sm ~%sm%~ BEGIN
            READ_SHORT 0 tmp_0
            off_1 += tmp_0 * 0x10
            READ_SHORT 6 tmp_0
            off_1 += 0x70 * tmp_0 + (tmp_0 = 0x2 ? 0x10 : 0)
            READ_SHORT 8 tmp_0
            READ_ASCII 0 tmp_1 (0x10)
            DELETE_BYTES 0 0x10
          END
          WRITE_ASCIIE off_0 + off_1 ~%tmp_1%~
          FOR (off_1 += 0x10; off_1 < 0x110; off_1 += 0x10) BEGIN
            WRITE_SHORT off_0 + off_1 + 0x8 tmp_0
          END
        END
      END ELSE BEGIN
        smc = 0x11
        msc = 0
        SPRINT ms fail
      END
    END
  END
END
off_0 += 0x110
WRITE_LONG 0x2b0 off_0
PATCH_IF ~%ms%~ STR_CMP fail && ~%sm%~ STR_CMP fail && smc = 0x11 BEGIN
  INSERT_BYTES off_0 0xc * msc
  WRITE_ASCIIE off_0 ~%ms%~
END ELSE BEGIN
  msc = 0
  WRITE_LONG 0x2b4 msc
END
smc = 0x11
WRITE_LONG 0x2ac smc
off_0 += 0xc * msc
WRITE_LONG 0x2c4 off_0
PATCH_IF ~%el%~ STR_CMP fail BEGIN
  INSERT_BYTES off_0 (elc * (0x30 + (((fv & 0x1) = 0x1) ? 0xd8 : 0)))
  WRITE_ASCIIE off_0 ~%el%~
END ELSE BEGIN
  elc = 0
  WRITE_LONG 0x2c8 elc
END
off_0 += (elc * (0x30 + (((fv & 0x1) = 0x1) ? 0xd8 : 0)))
WRITE_LONG 0x2bc off_0
PATCH_IF ~%il%~ STR_CMP fail BEGIN
  INSERT_BYTES off_0 (0x14 * ilc)
  WRITE_ASCIIE off_0 ~%il%~
END ELSE BEGIN
  ilc = 0
  WRITE_LONG 0x2c0 ilc
END
off_0 += 0x14 * ilc
WRITE_LONG 0x2b8 off_0
INSERT_BYTES off_0 0x50
PATCH_IF ~%is%~ STR_CMP fail BEGIN
  WRITE_ASCIIE off_0 ~%is%~
END ELSE BEGIN
  FOR (i_0 = 0; i_0 < 0x4c; i_0 += 2) BEGIN
    WRITE_SHORT off_0 + i1 0xffff
  END
END
SOURCE_SIZE = off_0 + 0x50
