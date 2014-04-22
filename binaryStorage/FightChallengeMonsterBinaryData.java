package com.ankamagames.wakfu.client.binaryStorage;

public class FightChallengeMonsterBinaryData implements dEZ {
    protected int az;
    protected short lv;
    protected short lw;
    protected int[] edB;
    
    public FightChallengeMonsterBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public short fq()
    {
        int i = this.lv;
        return (short)i;
    }
    
    public short fr()
    {
        int i = this.lw;
        return (short)i;
    }
    
    public int[] aNC()
    {
        return this.edB;
    }
    
    public void reset()
    {
        this.az = 0;
        this.lv = (short)0;
        this.lw = (short)0;
        this.edB = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        int i = a.getShort();
        this.lv = (short)i;
        int i0 = a.getShort();
        this.lw = (short)i0;
        this.edB = a.cli();
    }
    
    final public int gZ()
    {
        return aPw.eFR.getId();
    }
}