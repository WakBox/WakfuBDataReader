package com.ankamagames.wakfu.client.binaryStorage;

public class DungeonBinaryData implements dEZ {
    protected int az;
    protected short bYe;
    protected short aZF;
    protected short VT;
    protected int[] iKR;
    
    public DungeonBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public short Su()
    {
        int i = this.bYe;
        return (short)i;
    }
    
    public short oE()
    {
        int i = this.aZF;
        return (short)i;
    }
    
    public short vJ()
    {
        int i = this.VT;
        return (short)i;
    }
    
    public int[] cEZ()
    {
        return this.iKR;
    }
    
    public void reset()
    {
        this.az = 0;
        this.bYe = (short)0;
        this.aZF = (short)0;
        this.VT = (short)0;
        this.iKR = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        int i = a.getShort();
        this.bYe = (short)i;
        int i0 = a.getShort();
        this.aZF = (short)i0;
        int i1 = a.getShort();
        this.VT = (short)i1;
        this.iKR = a.cli();
    }
    
    final public int gZ()
    {
        return aPw.eFE.getId();
    }
}