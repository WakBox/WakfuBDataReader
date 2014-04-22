package com.ankamagames.wakfu.client.binaryStorage;

public class ItemSetBinaryData implements dEZ {
    protected short aKG;
    protected int elj;
    protected int[] eyi;
    protected deN eyj;
    
    public ItemSetBinaryData()
    {
        super();
    }
    
    public short nJ()
    {
        int i = this.aKG;
        return (short)i;
    }
    
    public int aZm()
    {
        return this.elj;
    }
    
    public int[] aZn()
    {
        return this.eyi;
    }
    
    public deN aZo()
    {
        return this.eyj;
    }
    
    public void reset()
    {
        this.aKG = (short)0;
        this.elj = 0;
        this.eyi = null;
        this.eyj = null;
    }
    
    public void a(ceb a)
    {
        int i = a.getShort();
        this.aKG = (short)i;
        this.elj = a.getInt();
        this.eyi = a.cli();
        int i0 = a.getInt();
        this.eyj = new deN(i0);
        int i1 = 0;
        while(i1 < i0)
        {
            int i2 = a.getInt();
            int[] a0 = a.cli();
            this.eyj.put(i2, (Object)a0);
            i1 = i1 + 1;
        }
    }
    
    final public int gZ()
    {
        return aPw.eDZ.getId();
    }
}